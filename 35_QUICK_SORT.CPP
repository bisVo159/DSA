#include<iostream>
using namespace std;

int partition(int* arr,int s,int e){
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot)
        count++;
    }
    //place pivot at right position
    int pivotindex=s+count;
    swap(arr[pivotindex],arr[s]);

    //left and right wala part sambal lete hain
    int i=s,j=e;
    while(s<pivotindex&&j>pivotindex){
while(arr[i]<=pivot){
    i++;
}
while(arr[j]>pivot){
    j--;
}
if(s<pivotindex&&j>pivotindex){
    swap(arr[i++],arr[j--]);
}
    }
    return pivotindex;
}

void quicksort(int* arr,int s,int e){
//base case
if(s>=e)
return;
int p=partition(arr,s,e);

//left part sort
quicksort(arr,s,p-1);
//right part sort
quicksort(arr,p+1,e);
}

int main(){
    int arr[10]={2,4,1,6,9,9,9,9,9,9};
    int n=10;
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}