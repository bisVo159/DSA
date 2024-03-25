#include<iostream>
using namespace std;

int main(){
    // int arr[10]={23,122,41,67};
   /* cout<<"address of first memory block of array "<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<"address of first memory block of array "<<&arr[0]<<endl;
    cout<<"value at first position of arraay "<<*arr<<endl;
    cout<<*arr+1<<endl;
    cout<<*(arr+1)<<endl;
    cout<<*(arr+2)<<endl;
    cout<<3[arr]<<endl;*/

    /*int temp[10]={1,2};
    cout<<sizeof(temp)<<endl;
    cout<<"1st "<<sizeof(*temp)<<endl;
    cout<<"2nd "<<sizeof(&temp)<<endl;
    int *ptr=&temp[0];
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(*ptr)<<endl;
    cout<<sizeof(&ptr)<<endl;*/

   /* int a[20]={1,2,3,4};
    cout<<"-> "<<&a[0]<<endl;
    cout<<&a<<endl;
    cout<<a<<endl;
    
    int *p=&a[0];
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<"-> "<<&p<<endl;*/

    int arr[10];
    // arr=arr+1;      NOT POSSIBLE
    int *ptr=&arr[0];
    cout<<ptr<<endl;
    ptr=ptr+1;
    cout<<ptr<<endl;

    return 0;
}