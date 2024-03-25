#include<iostream>
using namespace std;
/*
class template with multiple parameterd(one,two,or more than two)
syntax
template<class T1,class T2>
class nameOfClass{
    //body
}
*/

template<class T1,class T2>
class myClass{
    public:
    T1 data1;
    T2 data2;
    myClass(T1 d1,T2 d2){
        this->data1=d1;
        this->data2=d2;
    }
    void display(){
        cout<<this->data1<<"-"<<this->data2<<endl;
    }
};
int main(){
    myClass<int,char> obj(2,'c');
    obj.display();

    return 0;
}