#include<iostream>
#include<vector>
using namespace std;

int countDistinctWayToClimbStair(int nStair,int i){
    if(i==nStair)
    return 1;
    if(i>nStair)
    return 0;

    return (countDistinctWayToClimbStair(nStair,i+1)+countDistinctWayToClimbStair(nStair,i+2));
}

int solve(vector<int>&cost,int n){
    if(n==0)
    return cost[0];
    if(n==1)
    return cost[1];

    return min(solve(cost,n-1),solve(cost,n-2))+cost[n];
}
int solve2(vector<int>&cost,int n,vector<int>&dp){
    if(n==0)
    return cost[0];
    if(n==1)
    return cost[1];
    if(dp[n]!=-1)
    return dp[n];

    dp[n]= min(solve2(cost,n-1,dp),solve2(cost,n-2,dp))+cost[n];
    return dp[n];
}

int solve3(vector<int>&cost,int n){
    // step1: creation of dp array
    vector<int>dp(n+1);
    // step2: base case analysis
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<n;i++){
        dp[i]=min(dp[i-1],dp[i-2])+cost[i];
    }
    return min(dp[n-1],dp[n-2]);
}

int countDistinctWayToClimbStair(vector<int>&cost){
    int n=cost.size();
    // return min(solve(cost,n-1),solve(cost,n-2));    //recursion
    vector<int>dp(n,-1);
    // return min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));    //recursion + memorization
    return solve3(cost,n);
}

int main(){
    cout<<countDistinctWayToClimbStair(4,0)<<endl;

    vector<int>cost={5,4,7,9,8,3};
    cout<<"Minimum cost of climbing stair "<<countDistinctWayToClimbStair(cost)<<endl;

// ----->SPACEOPTIMIZATION<-----
    int prevCost2=cost[0];
    int prevCost1=cost[1];
    for(int i=2;i<cost.size();i++){
        int curr=min(prevCost1,prevCost2)+cost[i];
        prevCost2=prevCost1;
        prevCost1=curr;
    }
    cout<<"Minimum cost of climbing stair "<<min(prevCost1,prevCost2)<<endl;
    
    return 0;
}