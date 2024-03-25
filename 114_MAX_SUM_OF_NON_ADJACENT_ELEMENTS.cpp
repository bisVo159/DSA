#include<iostream>
#include<vector>
using namespace std;

int maxSumNonAdjacentElement(vector<int>&nums,int sum,int i,vector<int>&dp){
    if(i>=nums.size())
    return sum;
    if(dp[i]!=-1)
    return dp[i];

    int include=maxSumNonAdjacentElement(nums,sum+nums[i],i+2,dp);
    int exclude=maxSumNonAdjacentElement(nums,sum,i+1,dp);
    dp[i]= max(include,exclude);
    return dp[i];
}

int solve(vector<int>&nums,int n){
    //base case
    if(n<0)
    return 0;
    if(n==0)
    return nums[0];

    int incl=solve(nums,n-2)+nums[n];
    int excl=solve(nums,n-1);
    return max(incl,excl);
}

int solveMem(vector<int>&nums,int n,vector<int>&dp){
    //base case
    if(n<0)
    return 0;
    if(n==0)
    return nums[0];
    if(dp[n]!=-1)
    return dp[n];

    int incl=solveMem(nums,n-2,dp)+nums[n];
    int excl=solveMem(nums,n-1,dp);
    dp[n]= max(incl,excl);
    return dp[n];
}
int solveTab(vector<int>&nums){
    int incl,excl;
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        if(i-2<0)
         incl=0+nums[i];
        else
         incl=dp[i-2]+nums[i];

         excl=dp[i-1];
        dp[i]=max(incl,excl);
    }
    return dp[n-1];
}

int maxSumNonAdjacentElement(vector<int>&nums){
   int n=nums.size();
   //recursion
  /* int ans=solve(nums,n-1);
   return ans;*/

   //recursion + memorisation
//    vector<int>dp(n,-1);
//    return solveMem(nums,n-1,dp);

//recurrsion + Tabulation
return solveTab(nums);
}

int main(){
    vector<int>arr={9,8,8,9};
    vector<int>dp(arr.size(),-1);
    cout<<"Max sum of non adjacent element "<<maxSumNonAdjacentElement(arr,0,0,dp)<<endl;
    cout<<"Max sum of non adjacent element "<<maxSumNonAdjacentElement(arr)<<endl;

    //SPACEOPTIMISATION
    int prev2=0;
    int prev1=arr[0];
    for(int i=1;i<arr.size();i++){
       int incl=prev2+arr[i];
       int excl=prev1;
       int ans=max(incl,excl);
       prev2=prev1;
       prev1=ans;
    }   
    cout<<"Max sum of non adjacent element "<<prev1<<endl;
    return 0;
}