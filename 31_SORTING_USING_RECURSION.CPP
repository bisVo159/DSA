#include<bits/stdc++.h>
using namespace std;

void bubblesort(int *arr,int n){
     if(n==0||n==1)
     return;
     for(int i=0;i<n-1;i++){
         if(arr[i]>arr[i+1])
     swap(arr[i],arr[i+1]);
     }
    return bubblesort(arr,n-1);
}

/*void merge2(int arr1[],int n,int arr2[],int m,int arr3[]){
    int i=0,j=0;
    int k=0;
    while(i<n&&j<m){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }
        else{
               arr3[k++]=arr2[j++];
        }
    }
        //copy first array k element ko
        while(i<n){
            arr3[k++]=arr1[i++];
        }
        while(j<m){
            arr3[k++]=arr2[j++];
        }
}*/
/*void print(int ans[],int n){
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
}*/

void merge(int *arr,int s,int e){
      int mid=(s+e)/2;

      int len1=mid-s+1;
      int len2=e-mid;
      int *first=new int[len1];
      int *second=new int[len2];

      //copy values
      int mainarrayindex=s;
      for(int i=0;i<len1;i++){
          first[i]=arr[mainarrayindex++];
      }
       mainarrayindex=mid+1;
      for(int i=0;i<len2;i++){
          second[i]=arr[mainarrayindex++];
      }
      // merge 2 sorted arrays
      int index1=0;
      int index2=0;
      mainarrayindex=s;
      while(index1<len1&&index2<len2){
        if(first[index1]<second[index2]){
            arr[mainarrayindex++]=first[index1++];
        }
        else{
            arr[mainarrayindex++]=second[index2++];
        }
      }
      while(index1<len1){
        arr[mainarrayindex++]=first[index1++];
      }
      while(index2<len2){
        arr[mainarrayindex++]=second[index2++];
      }
delete []first;
delete []second;
}

void mergesort(int *arr,int s,int e){
    //base case
    if(s==e)
    return;
    int mid=(s+e)/2;
    //left part sort karna h
    mergesort(arr,s,mid);
    //right part sort karna h
    mergesort(arr,mid+1,e);
    //merge
    merge(arr,s,e);
}

int main(){
    //----->BUBBLE SORT<-----
   /* int arr[]={2,5,1,6,9};
    bubblesort(arr,5);
    for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";*/

    //----->MERGE 2 SORTED ARRAYS<------
/*int arr1[5]={1,3,5,7,9};
int arr2[3]={2,4,6};
int arr3[8]={0};
merge2(arr1,5,arr2,3,arr3);
print(arr3,8);*/


    //----->MERGE SORT<-----
    int arr[7]={38,27,43,3,9,82,10};
    mergesort(arr,0,6);
    for(int i=0;i<7;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}