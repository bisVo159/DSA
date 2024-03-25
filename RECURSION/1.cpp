#include<iostream>
#include<climits>
using namespace std;

void print(int arr[],int index,int length){
    if(index==length)
    return;

    cout<<arr[index]<<" ";
    print(arr,index+1,length);
}

void print2(int* arr,int size){
    if(size==0)
    return;

    cout<<*arr<<" ";
    print2(arr+1,size-1);
}

void maxElement(int arr[],int size,int &maxi){
    if(size==0)
    return;
    maxi=max(arr[0],maxi);
    maxElement(arr+1,size-1,maxi);
}

int getMax(int arr[],int index,int size){
    if(index==size)
    return INT_MIN;
    return max(arr[index],getMax(arr,index+1,size));
}

int main(){
    // print array
    int arr[5]={1,3,5,9,7};
    print(arr,0,5);
    cout<<endl;
    print2(arr,5);cout<<endl;

    int a[]={7,2,15,9,21,18};
    int max=a[0];
    maxElement(a+1,5,max);
    cout<<max<<endl;
    cout<<getMax(a,0,6)<<endl;
    
    return 0;
}