#include<iostream>
using namespace std;

template<class T1=int,class T2=float,class T3=char>
class Anik{
    public:
    T1 a;
    T2 b;
    T3 c;
    Anik(T1 x,T2 y,T3 z){
        a=x;
        b=y;
        c=z
    }
    void display(){
        cout<<"The value of a is "<<a<<endl;
        cout<<"The value of b is "<<b<<endl;
        cout<<"The value of c is "<<c<<endl;
    }
};

int main(){
    Anik<> a(4,6.4,'c');
    a.display();
    cout<<endl;
    Anik<float,char,char> b(1.4,'o','c');
    b.display();
    return 0;
}