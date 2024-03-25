#include<bits/stdc++.h>
#include<iostream>
#include<climits>
using namespace std;

int linearsearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int binarysearch(int arr[], int n, int key){
       int s=0;
       int e=n;
       while(s<=e){
           int mid=(s+e)/2;
           if(arr[mid]==key){
               return mid;
           }
           else if(arr[mid]>key){
               e=mid-1;
           }
           else{
               s=mid+1;
           }
       }
       return -1;
}

int main(){
    /*int n;
    cin>>n;*/
    /*int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }*/
   /*int arr[n];
   for (int i = 0; i < n; i++)
   {
       cin>>arr[i];
   }
   int maxNo=INT_MIN,minNo=INT_MAX;
for(int i=0;i<n;i++){
   maxNo=max(maxNo,arr[i]);
   minNo=min(minNo,arr[i]);
}
cout<<maxNo<<" "<<minNo;*/

// ----> SEARCHING IN ARRAY <------
/*int arr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
int key;
cin>>key;
cout<<linearsearch(arr,n,key);*/

// -------> BINARY SEARCH <--------
/*int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int key;
cin>>key;
cout<<binarysearch(arr,n,key);*/

    return 0;
}