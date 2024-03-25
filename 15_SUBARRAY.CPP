#include"bits/stdc++.h"
using namespace std;
int currentsum=0,maxsum=INT_MIN;
int kadane(int a[],int n){
    for(int i=0;i<n;i++){
        currentsum+=a[i];
        if(currentsum<0){
            currentsum=0;
        }
        maxsum=max(maxsum,currentsum);
    }
    return maxsum;
}
bool pairsum(int a[],int n,int k){
       for(int i=0;i<n-1;i++){
           for(int j=i+1;j<n;j++){
               if(a[i]+a[j]==k){
                   cout<<i<<""<<j<<endl;
                   return true;
               }
       }
       }
       return false;
}
bool pairsum1(int a[],int n,int k){
  int low=0;
  int high=n-1;
  while(low<high){
      if(a[low]+a[high]==k){
          cout<<low<<" "<<high<<endl;
          return true;
      }
      else if(a[low]+a[high]>k){
          high--;
      }
      else{
          low++;
      }
  }
  return false;
}

int main(){
    //------>MAXIMUM CIRCULAR SUBARRAY SUM<-----
   /* int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int wrapsum,nonwrapsum;
   nonwrapsum= kadane(a,n);
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=a[i];
         a[i]=-a[i];
    }
    wrapsum=totalsum+kadane(a,n);
    cout<<max(wrapsum,nonwrapsum);*/

    //------>PAIR SUM PROBLEM O(n2)<------
    int a[]={2,4,7,11,14,16,20,21};
    int k=31;
    //cout<<pairsum(a,8,k);
    cout<<pairsum1(a,8,k);

    
    return 0;
}