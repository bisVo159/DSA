#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int solveRec(vector<int>&coins,int x){
    if(x==0)
    return 0;
    if(x<0)
    return INT_MAX;

    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int ans=solveRec(coins,x-coins[i]);
        if(ans!=INT_MAX)
        mini=min(ans+1,mini);
    }
    return mini;
}
int solveMem(vector<int>&coins,int x,vector<int>&dp){
    if(x==0)
    return 0;
    if(x<0)
    return INT_MAX;
    if(dp[x]!=-1)
    return dp[x];

    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int ans=solveMem(coins,x-coins[i],dp);
        if(ans!=INT_MAX)
        mini=min(ans+1,mini);
    }
    dp[x]=mini;
    return dp[x];
}

int solveTab(vector<int>&coins,int x){
    vector<int>dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++){
        //i m trying to solve for every amount figure from 1 to x
        for(int j=0;j<coins.size();j++){
            if(i-coins[j]>=0&&dp[i-coins[j]]!=INT_MAX)
            dp[i]=min(dp[i],1+dp[i-coins[j]]);
        }
    }
    if(dp[x]==INT_MAX)
    return -1;

    return dp[x];
}

int minNoOfCoins(vector<int>&coins,int x){
    //recursion 
    /*int ans=solveRec(coins,x);
    if(ans==INT_MAX)
    return -1;
    return ans;*/

    //recursion + memorisation
   /*vector<int>dp(x+1,-1);
   int ans= solveMem(coins,x,dp);
    if(ans==INT_MAX)
    return -1;
    return ans;*/

    //Tabulation
    return solveTab(coins,x);
}

int main(){
    // ----->MINIMUM NUMBER OF COINS TO MAKE AN AMOUNT<-----
    vector<int>coins={1,2,3};
    int x=9;
    cout<<"Minimum number of coins to make "<<x<<" is "<<minNoOfCoins(coins,x)<<endl;
    
    return 0;
}