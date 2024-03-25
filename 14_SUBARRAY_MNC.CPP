#include<iostream>
#include"bits/stdc++.h"
using namespace std;

int main(){
    //----->SUBARRAY WHICH ADDITION TO A GIVEN NUMBER S<----
    /*int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int i=0,j=0,st=-1,en=-1,sum=0;
    while(j<n&&sum+a[j]<=s){
        sum+=a[j];
        j++;
    }
    if(sum==s){
        cout<<i+1<<" "<<j<<endl;
        return 0;
    }
    while(j<n){
        sum+=a[j];
        while(sum>s){
            sum-=a[i];
            i++;
        }

        if(sum==s){
            st=i+1;
            en=j+1;
            break;
        }
        j++;
    }
    cout<<st<<" "<<en<<endl;*/

    //-------->SMALLEST POSITIVE MISSING NUMBER<-------
   /* int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    const int N=1e6+2;
    bool check[N];
    for(int i=0;i<N;i++){
        check[i]=0;
    }

    for(int i=0;i<n;i++){
        if(a[i]>=0){
            check[a[i]]=1;
        }
    }
    int ans=-1;
    for(int i=0;i<N;i++){
        if(check[i]==false){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;*/

//----->PRINT ALL SUBARRAYS<------
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
/*for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        for(int k=i;k<=j;k++){
            cout<<a[k]<<" ";
        }
        cout<<endl;
    }
}*/

//------> MAXIMUM SUBARRAY SUM <-------

//---------->BRUREFORCE APPROACH O(n3)<---------
/*int maxSum=INT_MIN;
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        int sum=0;
        for(int k=i;k<=j;k++){
            sum+=a[k];
        }
        maxSum=max(maxSum,sum);
    }
}
cout<<maxSum<<endl;*/

//--------->CUMULATIVE SUM APPROACH O(n2)<----------
/*int currSum[n+1];
currSum[0]=0;
for(int i=1;i<=n;i++){
    currSum[i]=currSum[i-1]+a[i-1];
}
int maxSum=INT_MIN;
for(int i=1;i<=n;i++){
    int sum;
    for(int j=0;j<i;j++){
        sum=currSum[i]-currSum[j];
        maxSum=max(sum,maxSum);
    }
}
cout<<maxSum;*/

//--------->KADANE'S ALGORITHAM O(n)<---------
int currentSum=0;
int maxSum=INT_MIN;
for(int i=0;i<n;i++){
    currentSum+=a[i];
    if(currentSum<0){
        currentSum=0;
    }
    maxSum=max(maxSum,currentSum);
}
cout<<maxSum;
    return 0;
}