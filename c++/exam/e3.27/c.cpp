#include <iostream>
using namespace std;

class a
{
    public:
    int x;
    int y;
    a(int k,int l):y(k),x(l){};

};
class Character {
public: Character(){cout<<"Character"<<endl;} 
};
class BookCharacter: public Character {
public: BookCharacter(){cout<<"BookCharacter"<<endl;} 
};
class ZooAnimal{
public: ZooAnimal(){cout<<"ZooAnimal"<<endl;} 
};
class Bear:public virtual ZooAnimal{ 
public: Bear(){cout<<"Bear"<<endl;} 
};
class ToyAnimal {
public: ToyAnimal(){cout<<"ToyAnimal"<<endl;} 
};

class TeddyBear: public BookCharacter, public virtual ToyAnimal, public Bear
{ public: TeddyBear(){cout<<"TeddyBear"<<endl;} 
};
int main()
{ TeddyBear obj; return 0;}