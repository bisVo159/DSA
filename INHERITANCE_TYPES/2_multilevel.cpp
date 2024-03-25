#include<iostream>
using namespace std;

class Animal{
    public:
    int age;
    int weight;

    public:
    void speak(){
        cout<<"Speaking "<<endl;
    }
};
class Dog:public Animal{
      
};
class Germanshephered:public Dog{
      
};

int main(){
   Germanshephered g;
   g.speak();
    return 0;
}