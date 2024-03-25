#include<iostream>
#include<vector>
using namespace std;

bool solve(int index,int N,int arr[],int target){
    if(target==0)
    return 1;
    if(index==N||target<0)
    return 0;

    int include=solve(index+1,N,arr,target-arr[index]);
    if(include)
    return include;
    int exclude=solve(index+1,N,arr,target);
    return exclude;
}
bool solveMem(int index,int N,int arr[],int target,vector<vector<int>>&dp){
    if(target==0)
    return 1;
    if(index==N||target<0)
    return 0;
    if(dp[index][target]!=-1);
    return dp[index][target];

    int include=solveMem(index+1,N,arr,target-arr[index],dp);
    int exclude=solveMem(index+1,N,arr,target,dp);
    return dp[index][target]=include or exclude;
}
bool solveTab(int N,int arr[],int t){
    vector<vector<int>>dp(N+1,vector<int>(t+1,0));
    for(int index=0;index<=N;index++)
    dp[index][0]=1;

    for(int index=N-1;index>=0;index--){
        for(int target=1;target<=t;target++){
                bool include=0;
                if(target-arr[index]>=0)
                         include=dp[index+1][target-arr[index]];
                bool exclude=dp[index+1][target];
                dp[index][target]=include or exclude;
        }
    }
    return dp[0][t];
}
bool solveOpt(int N,int arr[],int t){
    vector<int>curr(t+1,0);
    vector<int>next(t+1,0);
    curr[0]=0;
   next[0]=1;

    for(int index=N-1;index>=0;index--){
        for(int target=1;target<=t;target++){
                bool include=0;
                if(target-arr[index]>=0)
                         include=next[target-arr[index]];
                bool exclude=next[target];
                curr[target]=include or exclude;
        }
        next=curr;
    }
    return curr[t];
}

int equalPortion(int N,int arr[]){
    int total=0;
    for(int i=0;i<N;i++)
    total=total+arr[i];
    int target=total/2;
    // if(total%2==0)
    // return  solve(0,N,arr,target);
    // return 0;

    // recursion + memorisation
    // vector<vector<int>>dp(N,vector<int>(target+1,-1));
    // if(total%2==0)
    // return  solveMem(0,N,arr,target,dp);
    // return 0;

    // tabulation
    // if(total%2==0)
    // return  solveTab(N,arr,target);
    // return 0;

    // space-optimisation
    if(total%2==0)
    return  solveOpt(N,arr,target);
    return 0;
}

int main(){
    // int arr[]={1,3,5};
    int arr[]={1,5,11,5};
    cout<<equalPortion(4,arr)<<endl;
    
    return 0;
}