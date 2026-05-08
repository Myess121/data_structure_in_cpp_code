#include <graphics.h>
#include <windows.h>
#include <cwchar>
#include <sstream>
#include <string>

#pragma execution_character_set("utf-8")

using namespace std;

template <typename T>
class SeqList {
private:
    T* data;
    int len;
    int cap;

    void expand() {
        int newCap = cap * 2;
        T* newData = new T[newCap];
        for (int i = 0; i < len; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        cap = newCap;
    }

public:
    SeqList(int c = 10) {
        cap = c;
        len = 0;
        data = new T[cap];
    }

    SeqList(const SeqList& other) {
        cap = other.cap;
        len = other.len;
        data = new T[cap];
        for (int i = 0; i < len; ++i) {
            data[i] = other.data[i];
        }
    }

    ~SeqList() {
        delete[] data;
    }

    SeqList& operator=(const SeqList& other) {
        if (this != &other) {
            delete[] data;
            cap = other.cap;
            len = other.len;
            data = new T[cap];
            for (int i = 0; i < len; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void push_back(const T& value) {
        if (len >= cap) {
            expand();
        }
        data[len++] = value;
    }

    bool removeAt(int index) {
        if (index < 0 || index >= len) {
            return false;
        }
        for (int i = index; i < len - 1; ++i) {
            data[i] = data[i + 1];
        }
        --len;
        return true;
    }

    int size() const {
        return len;
    }

    void clear() {
        len = 0;
    }

    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }
};

struct Place {
    int id;
    wstring name;
    int x;
    int y;
    int length;
    int width;
    wstring description;
    int type;

    Place() {
        id = 0;
        x = 0;
        y = 0;
        length = 0;
        width = 0;
        type = 0;
    }
};

struct CampusMap {
    int id;
    wstring schoolName;
    int mapLength;
    int mapWidth;
    int nextPlaceId;
    SeqList<Place> places;

    CampusMap() : places(20) {
        id = 0;
        mapLength = 0;
        mapWidth = 0;
        nextPlaceId = 1;
    }
};

struct Button {
    int left;
    int top;
    int right;
    int bottom;
    wstring text;
};

class CampusGISWindowApp {
private:
    SeqList<CampusMap> maps;
    int currentMapIndex;
    int mouseX;
    int mouseY;

    static const int WIN_W = 1280;
    static const int WIN_H = 760;
    static const int MAP_LEFT = 30;
    static const int MAP_TOP = 60;
    static const int PANEL_LEFT = 920;
    static const int PANEL_W = 330;

    Button buttons[9];

    void initButtons() {
        const wchar_t* labels[9] = {
            L"创建地图", L"切换地图", L"增加建筑",
            L"显示建筑信息", L"删除建筑", L"修改建筑",
            L"保存地图", L"导入地图", L"退出系统"
        };
        for (int i = 0; i < 9; ++i) {
            buttons[i].left = PANEL_LEFT + 20;
            buttons[i].right = PANEL_LEFT + PANEL_W - 20;
            buttons[i].top = 80 + i * 60;
            buttons[i].bottom = buttons[i].top + 42;
            buttons[i].text = labels[i];
        }
    }

    void showMessage(const wstring& text, const wchar_t* title = L"提示") const {
        MessageBoxW(GetHWnd(), text.c_str(), title, MB_OK | MB_ICONINFORMATION);
    }

    void showError(const wstring& text) const {
        MessageBoxW(GetHWnd(), text.c_str(), L"错误", MB_OK | MB_ICONERROR);
    }

    bool inputText(const wchar_t* title, const wchar_t* prompt, wstring& result, const wchar_t* def = L"") const {
        wchar_t buffer[512];
        wcsncpy_s(buffer, def, _TRUNCATE);
        bool ok = InputBox(buffer, 512, prompt, title, def, 0, 0, false);
        if (!ok) {
            return false;
        }
        result = buffer;
        return true;
    }

    bool inputInt(const wchar_t* title, const wchar_t* prompt, int& value, int def = 0) const {
        wchar_t defText[64];
        wchar_t buffer[128];
        _snwprintf_s(defText, 64, _TRUNCATE, L"%d", def);
        bool ok = InputBox(buffer, 128, prompt, title, defText, 0, 0, false);
        if (!ok) {
            return false;
        }
        wchar_t* endPtr = NULL;
        long num = wcstol(buffer, &endPtr, 10);
        if (endPtr == buffer || *endPtr != L'\0') {
            showError(L"请输入整数。");
            return false;
        }
        value = (int)num;
        return true;
    }

    bool hasCurrentMap() const {
        return currentMapIndex >= 0 && currentMapIndex < maps.size();
    }

    CampusMap& currentMap() {
        return maps[currentMapIndex];
    }

    const CampusMap& currentMap() const {
        return maps[currentMapIndex];
    }

    int findMapIndexById(int id) const {
        for (int i = 0; i < maps.size(); ++i) {
            if (maps[i].id == id) {
                return i;
            }
        }
        return -1;
    }

    int findPlaceIndexById(const CampusMap& map, int id) const {
        for (int i = 0; i < map.places.size(); ++i) {
            if (map.places[i].id == id) {
                return i;
            }
        }
        return -1;
    }

    wstring typeName(int type) const {
        switch (type) {
        case 1: return L"教学楼";
        case 2: return L"食堂";
        case 3: return L"图书馆";
        case 4: return L"体育场";
        case 5: return L"湖泊";
        default: return L"其他";
        }
    }

    COLORREF typeColor(int type) const {
        switch (type) {
        case 1: return RGB(122, 162, 247);
        case 2: return RGB(245, 164, 108);
        case 3: return RGB(243, 213, 91);
        case 4: return RGB(110, 196, 121);
        case 5: return RGB(108, 196, 245);
        default: return RGB(190, 190, 190);
        }
    }

    bool inMapRange(const CampusMap& map, const Place& p) const {
        return p.x >= 0 && p.y >= 0 &&
               p.length > 0 && p.width > 0 &&
               p.x + p.length <= map.mapLength &&
               p.y + p.width <= map.mapWidth;
    }

    bool conflict(const Place& a, const Place& b) const {
        if (a.x + a.length <= b.x) return false;
        if (b.x + b.length <= a.x) return false;
        if (a.y + a.width <= b.y) return false;
        if (b.y + b.width <= a.y) return false;
        return true;
    }

    bool canPlace(const CampusMap& map, const Place& p, int ignoreId = -1) const {
        if (!inMapRange(map, p)) {
            showError(L"建筑超出地图范围，或者长宽不合法。");
            return false;
        }
        for (int i = 0; i < map.places.size(); ++i) {
            if (map.places[i].id == ignoreId) {
                continue;
            }
            if (conflict(map.places[i], p)) {
                showError(L"该建筑与已有建筑发生位置冲突。");
                return false;
            }
        }
        return true;
    }

    bool inputPlace(Place& p, int defaultId) const {
        wstring text;
        int num;

        if (!inputText(L"输入名称", L"请输入地点或建筑名称", text)) return false;
        p.name = text;

        if (!inputInt(L"输入类型", L"请输入类型：1教学楼 2食堂 3图书馆 4体育场 5湖泊 6其他", num, 1)) return false;
        if (num < 1 || num > 6) {
            num = 6;
        }
        p.type = num;

        if (!inputInt(L"输入坐标", L"请输入左上角横坐标 x", p.x, 0)) return false;
        if (!inputInt(L"输入坐标", L"请输入左上角纵坐标 y", p.y, 0)) return false;
        if (!inputInt(L"输入尺寸", L"请输入占地长度 l", p.length, 50)) return false;
        if (!inputInt(L"输入尺寸", L"请输入占地宽度 w", p.width, 40)) return false;
        if (!inputText(L"输入描述", L"请输入功能描述", text)) return false;
        p.description = text;
        p.id = defaultId;
        return true;
    }

    wstring placeInfo(const Place& p) const {
        wstringstream ss;
        ss << L"ID: " << p.id << L"\n";
        ss << L"名称: " << p.name << L"\n";
        ss << L"类型: " << typeName(p.type) << L"\n";
        ss << L"坐标: (" << p.x << L", " << p.y << L")\n";
        ss << L"占地: " << p.length << L" x " << p.width << L"\n";
        ss << L"描述: " << p.description;
        return ss.str();
    }

    wstring mapInfo(const CampusMap& map) const {
        wstringstream ss;
        ss << L"地图编号: " << map.id << L"\n";
        ss << L"校园名称: " << map.schoolName << L"\n";
        ss << L"地图大小: " << map.mapLength << L" x " << map.mapWidth << L"\n";
        ss << L"建筑数量: " << map.places.size();
        return ss.str();
    }

    void saveMapToFile() {
        if (!hasCurrentMap()) {
            showError(L"请先创建地图。");
            return;
        }

        wstring path;
        if (!inputText(L"保存地图", L"请输入保存路径，例如 E:\\cpp文件\\map.txt", path, L"E:\\cpp文件\\map.txt")) {
            return;
        }

        FILE* fp = NULL;
        _wfopen_s(&fp, path.c_str(), L"w, ccs=UTF-8");
        if (!fp) {
            showError(L"文件打开失败。");
            return;
        }

        const CampusMap& map = currentMap();
        fwprintf(fp, L"%ls\n", map.schoolName.c_str());
        fwprintf(fp, L"%d %d %d\n", map.mapLength, map.mapWidth, map.nextPlaceId);
        fwprintf(fp, L"%d\n", map.places.size());
        for (int i = 0; i < map.places.size(); ++i) {
            const Place& p = map.places[i];
            fwprintf(fp, L"%d\n", p.id);
            fwprintf(fp, L"%ls\n", p.name.c_str());
            fwprintf(fp, L"%d %d %d %d %d\n", p.type, p.x, p.y, p.length, p.width);
            fwprintf(fp, L"%ls\n", p.description.c_str());
        }
        fclose(fp);
        showMessage(L"保存成功。");
    }

    bool readLineFile(FILE* fp, wchar_t* buffer, int size) const {
        if (!fgetws(buffer, size, fp)) {
            return false;
        }
        int len = (int)wcslen(buffer);
        while (len > 0 && (buffer[len - 1] == L'\n' || buffer[len - 1] == L'\r')) {
            buffer[len - 1] = L'\0';
            --len;
        }
        return true;
    }

    void loadMapFromFile() {
        wstring path;
        if (!inputText(L"导入地图", L"请输入导入文件路径", path, L"E:\\cpp文件\\map.txt")) {
            return;
        }

        FILE* fp = NULL;
        _wfopen_s(&fp, path.c_str(), L"r, ccs=UTF-8");
        if (!fp) {
            showError(L"文件打开失败。");
            return;
        }

        CampusMap map;
        wchar_t line[1024];
        int count = 0;

        if (!readLineFile(fp, line, 1024)) {
            fclose(fp);
            showError(L"文件内容不完整。");
            return;
        }
        map.schoolName = line;

        if (fwscanf_s(fp, L"%d %d %d", &map.mapLength, &map.mapWidth, &map.nextPlaceId) != 3) {
            fclose(fp);
            showError(L"文件内容格式错误。");
            return;
        }
        if (fwscanf_s(fp, L"%d", &count) != 1) {
            fclose(fp);
            showError(L"文件内容格式错误。");
            return;
        }
        fgetwc(fp);

        for (int i = 0; i < count; ++i) {
            Place p;
            if (fwscanf_s(fp, L"%d", &p.id) != 1) {
                fclose(fp);
                showError(L"建筑数据读取失败。");
                return;
            }
            fgetwc(fp);
            if (!readLineFile(fp, line, 1024)) {
                fclose(fp);
                showError(L"建筑名称读取失败。");
                return;
            }
            p.name = line;
            if (fwscanf_s(fp, L"%d %d %d %d %d", &p.type, &p.x, &p.y, &p.length, &p.width) != 5) {
                fclose(fp);
                showError(L"建筑尺寸读取失败。");
                return;
            }
            fgetwc(fp);
            if (!readLineFile(fp, line, 1024)) {
                fclose(fp);
                showError(L"建筑描述读取失败。");
                return;
            }
            p.description = line;
            map.places.push_back(p);
        }

        fclose(fp);
        map.id = maps.size() + 1;
        maps.push_back(map);
        currentMapIndex = maps.size() - 1;
        showMessage(L"导入成功。");
    }

    void createMap() {
        CampusMap map;
        wstring name;

        if (!inputText(L"创建地图", L"请输入校园名称", name)) {
            return;
        }
        if (!inputInt(L"创建地图", L"请输入地图长度 L", map.mapLength, 800)) {
            return;
        }
        if (!inputInt(L"创建地图", L"请输入地图宽度 W", map.mapWidth, 500)) {
            return;
        }

        if (map.mapLength <= 0 || map.mapWidth <= 0) {
            showError(L"地图长宽必须大于 0。");
            return;
        }

        map.id = maps.size() + 1;
        map.schoolName = name;
        map.nextPlaceId = 1;
        maps.push_back(map);
        currentMapIndex = maps.size() - 1;
        showMessage(L"地图创建成功。");
    }

    void switchMap() {
        if (maps.size() == 0) {
            showError(L"当前还没有地图。");
            return;
        }
        wstringstream ss;
        ss << L"已有地图：\n";
        for (int i = 0; i < maps.size(); ++i) {
            ss << L"编号 " << maps[i].id << L"："
               << maps[i].schoolName << L" (" << maps[i].mapLength << L"x" << maps[i].mapWidth << L")\n";
        }
        showMessage(ss.str(), L"地图列表");

        int id;
        if (!inputInt(L"切换地图", L"请输入要切换的地图编号", id, 1)) {
            return;
        }
        int index = findMapIndexById(id);
        if (index == -1) {
            showError(L"没有找到该地图编号。");
            return;
        }
        currentMapIndex = index;
        showMessage(L"地图切换成功。");
    }

    void addPlace() {
        if (!hasCurrentMap()) {
            showError(L"请先创建地图。");
            return;
        }

        CampusMap& map = currentMap();
        Place p;
        if (!inputPlace(p, map.nextPlaceId)) {
            return;
        }
        if (!canPlace(map, p)) {
            return;
        }

        map.places.push_back(p);
        map.nextPlaceId++;
        showMessage(L"建筑添加成功。");
    }

    void showPlaces() const {
        if (!hasCurrentMap()) {
            showError(L"请先创建地图。");
            return;
        }
        const CampusMap& map = currentMap();
        if (map.places.size() == 0) {
            showMessage(L"当前地图中没有任何建筑。");
            return;
        }

        wstringstream ss;
        ss << L"当前地图：" << map.schoolName << L"\n\n";
        for (int i = 0; i < map.places.size(); ++i) {
            ss << L"[" << i + 1 << L"] " << map.places[i].name
               << L"  ID=" << map.places[i].id
               << L"  坐标=(" << map.places[i].x << L"," << map.places[i].y << L")\n";
        }
        showMessage(ss.str(), L"建筑列表");
    }

    void deletePlace() {
        if (!hasCurrentMap()) {
            showError(L"请先创建地图。");
            return;
        }

        int id;
        if (!inputInt(L"删除建筑", L"请输入要删除的建筑 ID", id, 1)) {
            return;
        }

        CampusMap& map = currentMap();
        int index = findPlaceIndexById(map, id);
        if (index == -1) {
            showError(L"没有找到该建筑 ID。");
            return;
        }

        map.places.removeAt(index);
        showMessage(L"删除成功。");
    }

    void modifyPlace() {
        if (!hasCurrentMap()) {
            showError(L"请先创建地图。");
            return;
        }

        int id;
        if (!inputInt(L"修改建筑", L"请输入要修改的建筑 ID", id, 1)) {
            return;
        }

        CampusMap& map = currentMap();
        int index = findPlaceIndexById(map, id);
        if (index == -1) {
            showError(L"没有找到该建筑 ID。");
            return;
        }

        Place temp = map.places[index];
        if (!inputPlace(temp, id)) {
            return;
        }
        if (!canPlace(map, temp, id)) {
            return;
        }

        map.places[index] = temp;
        showMessage(L"修改成功。");
    }

    int buttonAt(int x, int y) const {
        for (int i = 0; i < 9; ++i) {
            if (x >= buttons[i].left && x <= buttons[i].right &&
                y >= buttons[i].top && y <= buttons[i].bottom) {
                return i;
            }
        }
        return -1;
    }

    const Place* hoveredPlace() const {
        if (!hasCurrentMap()) {
            return NULL;
        }
        const CampusMap& map = currentMap();
        double scaleX = (PANEL_LEFT - MAP_LEFT - 30) * 1.0 / map.mapLength;
        double scaleY = (WIN_H - MAP_TOP - 40) * 1.0 / map.mapWidth;
        double scale = scaleX < scaleY ? scaleX : scaleY;
        if (scale < 1.0) {
            scale = 1.0;
        }

        int mapRight = MAP_LEFT + (int)(map.mapLength * scale);
        int mapBottom = MAP_TOP + (int)(map.mapWidth * scale);
        if (mouseX < MAP_LEFT || mouseX > mapRight || mouseY < MAP_TOP || mouseY > mapBottom) {
            return NULL;
        }

        int px = (int)((mouseX - MAP_LEFT) / scale);
        int py = (int)((mouseY - MAP_TOP) / scale);
        for (int i = 0; i < map.places.size(); ++i) {
            const Place& p = map.places[i];
            if (px >= p.x && px <= p.x + p.length &&
                py >= p.y && py <= p.y + p.width) {
                return &p;
            }
        }
        return NULL;
    }

    void drawButton(const Button& btn, bool hover) const {
        setlinecolor(RGB(110, 110, 110));
        setfillcolor(hover ? RGB(220, 236, 255) : RGB(245, 245, 245));
        solidrectangle(btn.left, btn.top, btn.right, btn.bottom);
        rectangle(btn.left, btn.top, btn.right, btn.bottom);
        settextcolor(BLACK);
        RECT rect = { btn.left, btn.top, btn.right, btn.bottom };
        drawtext(btn.text.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }

    void drawRightPanel() const {
        setlinecolor(RGB(180, 180, 180));
        setfillcolor(RGB(250, 250, 250));
        solidrectangle(PANEL_LEFT, 0, WIN_W, WIN_H);
        line(PANEL_LEFT, 0, PANEL_LEFT, WIN_H);

        settextcolor(BLACK);
        RECT titleRect = { PANEL_LEFT + 20, 20, WIN_W - 20, 50 };
        drawtext(L"操作面板", &titleRect, DT_LEFT | DT_VCENTER | DT_SINGLELINE);

        int hoverIndex = buttonAt(mouseX, mouseY);
        for (int i = 0; i < 9; ++i) {
            drawButton(buttons[i], i == hoverIndex);
        }

        RECT infoRect = { PANEL_LEFT + 15, 630, WIN_W - 15, WIN_H - 15 };
        setlinecolor(RGB(180, 180, 180));
        rectangle(infoRect.left, infoRect.top, infoRect.right, infoRect.bottom);

        wstring info = L"未选择地图";
        if (hasCurrentMap()) {
            info = mapInfo(currentMap());
        }
        RECT mapInfoRect = { infoRect.left + 10, infoRect.top + 10, infoRect.right - 10, infoRect.top + 90 };
        drawtext(info.c_str(), &mapInfoRect, DT_LEFT | DT_WORDBREAK);

        const Place* p = hoveredPlace();
        if (p) {
            wstring detail = placeInfo(*p);
            RECT detailRect = { infoRect.left + 10, infoRect.top + 100, infoRect.right - 10, infoRect.bottom - 10 };
            drawtext(detail.c_str(), &detailRect, DT_LEFT | DT_WORDBREAK);
        }
        else {
            RECT tipRect = { infoRect.left + 10, infoRect.top + 100, infoRect.right - 10, infoRect.bottom - 10 };
            drawtext(L"把鼠标移动到地图中的建筑上，可以查看详细信息。", &tipRect, DT_LEFT | DT_WORDBREAK);
        }
    }

    void drawMapArea() const {
        setfillcolor(WHITE);
        solidrectangle(0, 0, PANEL_LEFT - 1, WIN_H);
        RECT mapTitleRect = { MAP_LEFT, 15, 400, 45 };
        drawtext(L"校园地图显示区", &mapTitleRect, DT_LEFT | DT_VCENTER | DT_SINGLELINE);

        if (!hasCurrentMap()) {
            RECT emptyRect = { 60, 120, PANEL_LEFT - 60, 180 };
            drawtext(L"请先点击“创建地图”或“导入地图”。", &emptyRect, DT_CENTER | DT_VCENTER | DT_WORDBREAK);
            return;
        }

        const CampusMap& map = currentMap();
        double scaleX = (PANEL_LEFT - MAP_LEFT - 30) * 1.0 / map.mapLength;
        double scaleY = (WIN_H - MAP_TOP - 40) * 1.0 / map.mapWidth;
        double scale = scaleX < scaleY ? scaleX : scaleY;
        if (scale < 1.0) {
            scale = 1.0;
        }

        int mapRight = MAP_LEFT + (int)(map.mapLength * scale);
        int mapBottom = MAP_TOP + (int)(map.mapWidth * scale);

        setlinecolor(BLACK);
        rectangle(MAP_LEFT, MAP_TOP, mapRight, mapBottom);

        for (int i = 0; i < map.places.size(); ++i) {
            const Place& p = map.places[i];
            int x1 = MAP_LEFT + (int)(p.x * scale);
            int y1 = MAP_TOP + (int)(p.y * scale);
            int x2 = MAP_LEFT + (int)((p.x + p.length) * scale);
            int y2 = MAP_TOP + (int)((p.y + p.width) * scale);

            setfillcolor(typeColor(p.type));
            solidrectangle(x1, y1, x2, y2);
            setlinecolor(BLACK);
            rectangle(x1, y1, x2, y2);

            RECT r = { x1 + 2, y1 + 2, x2 - 2, y2 - 2 };
            drawtext(p.name.c_str(), &r, DT_CENTER | DT_VCENTER | DT_WORDBREAK);
        }
    }

    void redraw() const {
        BeginBatchDraw();
        cleardevice();
        drawMapArea();
        drawRightPanel();
        EndBatchDraw();
    }

    void handleButton(int index, bool& running) {
        switch (index) {
        case 0: createMap(); break;
        case 1: switchMap(); break;
        case 2: addPlace(); break;
        case 3: showPlaces(); break;
        case 4: deletePlace(); break;
        case 5: modifyPlace(); break;
        case 6: saveMapToFile(); break;
        case 7: loadMapFromFile(); break;
        case 8: running = false; break;
        default: break;
        }
    }

public:
    CampusGISWindowApp() : maps(5) {
        currentMapIndex = -1;
        mouseX = 0;
        mouseY = 0;
        initButtons();
    }

    void run() {
        initgraph(WIN_W, WIN_H);
        setbkcolor(WHITE);
        cleardevice();
        setbkmode(TRANSPARENT);
        settextcolor(BLACK);

        bool running = true;
        while (running) {
            redraw();

            while (MouseHit()) {
                MOUSEMSG msg = GetMouseMsg();
                mouseX = msg.x;
                mouseY = msg.y;

                if (msg.uMsg == WM_LBUTTONDOWN) {
                    int index = buttonAt(msg.x, msg.y);
                    if (index != -1) {
                        handleButton(index, running);
                    }
                }
            }
            Sleep(20);
        }

        closegraph();
    }
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    CampusGISWindowApp app;
    app.run();
    return 0;
}
