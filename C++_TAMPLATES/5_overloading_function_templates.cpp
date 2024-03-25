#include<iostream>
using namespace std;

template<class T>
class Anik{
    public:
    T data;
    Anik(T a){
    data=a;    
    }
    void display();
};
template<class T>
void Anik<T>:: display(){
        cout<<data<<endl;
    }

void func(int a){
    cout<<"I am first func() "<<a<<endl;
}

template<class T>
void func(T a){
    cout<<"I am tempalatised func() "<<a<<endl;
}

int main(){
    // Anik<float>a(5.7);
    // cout<<a.data<<endl;
    // a.display();

    func(4);    //Exact match takes the heighest priority
    
    return 0;
}