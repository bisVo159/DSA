#include<iostream>
using namespace std;

/*class A{
    public:
    //function overloading
    void sayhello(){
        cout<<"Hello Anik Biswas"<<endl;
    }
    int sayhello(string name,int n){
        cout<<"Hello "<<name<<endl;
        return n;
    }
    void sayhello(string name){
        cout<<"Hello "<<name<<endl;
    }
    void sayhello(char name){
        cout<<"Hello "<<name<<endl;
    }
};*/

/*class B{
    public:
    int a,b;
    public:
    void operator+(B &obj){*/
        /*int value1=this->a;
        int value2=obj.a;
          cout<<"output "<<value2-value1<<endl;*/
/*cout<<"hello world"<<endl;
    }

    void  operator()(){
        cout<<"man bracket hu "<<this->a<<endl;
    }
};*/

//Runtime polimorphism
//Function overriding
class Animal{
    public:
    void speak(){
         cout<<"speaking"<<endl;
    }
};
class Dog:public Animal{
    public:
    void speak(){
         cout<<"Barking"<<endl;
    }
};

int main(){
    //Compile timee polymorphism
    //function overloading
   /* A obj;
    obj.sayhello();*/

    //operator overloading
   /* B obj1,obj2;
    obj1.a=4;
    obj2.a=7;
    obj1+obj2;
    obj1(); */

    //Runtime polymorphism
    //Function overriding
   Dog obj;
   obj.speak();
    
    return 0;
}