#include<iostream>
using namespace std;

void print(int *p){
    cout<<*p<<endl;
}

void update(int *p){
  /*  cout<<p<<endl;
    cout<<*p<<endl;
    p=p+1;
    cout<<"Inside "<<p<<endl;
    cout<<*p<<endl;*/
    *p=*p+1;
}

int getsum(int arr[],int n){
    cout<<"Size :"<<sizeof(arr)<<endl;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    return sum;
}

int main(){
    int value=5;
    int *p=&value;
   // print(p);
   cout<<"Before "<<p<<endl;
   cout<<"After "<<*p<<endl;
   update(p);
   cout<<"After "<<p<<endl;
   cout<<"After "<<*p<<endl;
   cout<<value<<endl;

   int arr[5]={1,2,3,4,5};
   cout<<"sum is "<<getsum(arr+3,2)<<endl;
    return 0;
}