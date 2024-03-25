#include<iostream>
using namespace std;

void update(int **p){
    //p=p+1;      //any change ? - > No

    //*p=*p+1;       //any change ? - > yes

    **p=**p+1;       //any change ? - > yes
}

int main(){
    int i=5;
    int *p=&i;
    int** p2=&p;

   /* cout<<"value at p "<<p<<endl;
    cout<<"address of p "<<&p<<endl;
    cout<<"address of p "<<p2<<endl;

    cout<<"address of i "<<*p2<<endl;

    //printing value of i
    cout<<"value of i "<<i<<endl;
    cout<<"value of i "<<*p<<endl;
    cout<<"value of i "<<**p2<<endl;

    //printing value at p
    cout<<"value at p "<<&i<<endl;
    cout<<"value at p "<<p<<endl;
    cout<<"value at p "<<*p2<<endl;

    //printing value at p2
    cout<<&p<<endl;
    cout<<p2<<endl;*/

    cout<<"before "<<i<<endl;
    cout<<"before "<<p<<endl;
    cout<<"before "<<p2<<endl;
    update(p2);
    cout<<"after "<<i<<endl;
    cout<<"after "<<p<<endl;
    cout<<"after "<<p2<<endl;
    return 0;
}