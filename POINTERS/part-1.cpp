#include<iostream>
using namespace std;

int main(){
   /* int num=5;
    //address of operator
    cout<<"address of num is "<<&num<<endl;
    int *p=&num;
    cout<<"value of num is :"<<*p<<endl;
    cout<<"address of num is :"<<p<<endl;

    double d=4.2;
    double* p2=&d;
     cout<<"value if d is :"<<*p2<<endl;
    cout<<"address if d is :"<<p2<<endl;

    cout<<"size of integer is "<<sizeof(num)<<endl;
    cout<<"size of pointer is "<<sizeof(p)<<endl;
    cout<<"size of pointer is "<<sizeof(p2)<<endl;*/

    //pointer to int is created, and pointing to some garbage address
    // int *p;
    // cout<<*p<<endl;
   /* int i=5;
    int* q=&i;
     cout<<q<<endl;
    cout<<*q<<endl;
    int* p=0;
    p=&i;
    cout<<p<<endl;
    cout<<*p<<endl;*/

   /* int num=5;
    int a=num;
    a++;
    cout<<num<<endl;
    cout<<a<<endl;

    int *p=&num;
     a=*p;
    a++;
    cout<<num<<endl;  //will not be changed
   (*p)++;
    cout<<num<<endl;

    //copy pointer
    int *q=p;
    cout<<p<<" "<<q<<endl;
    cout<<*p<<" "<<*q<<endl;*/

    //important concept
    int i=3;
    int *t=&i;
    cout<<(*t)++<<endl;
    cout<<*t<<endl;
    cout<<"Before "<<t<<endl;
    t=t+1;
    //t will be shifted to next int location
    cout<<"After "<<t<<endl;
    cout<<*t<<endl;      //Garbage value
    return 0;
}