#include<iostream>
#include<vector>
using namespace std;

int solve(int index,int buy,vector<int>&prices){
    if(index==prices.size())
    return 0;

    int profit=0;
    if(buy){
    int Buy=-prices[index]+solve(index+1,0,prices);
    int Skip=0+solve(index+1,buy,prices);
    profit=max(Buy,Skip);
    }
    else{
    int Sale=prices[index]+solve(index+1,1,prices);
    int Skip=0+solve(index+1,buy,prices);
    profit=max(Sale,Skip);
    }
    return profit;
}
int solveMem(int index,int buy,vector<int>&prices,vector<vector<int>>&dp){
    if(index==prices.size())
    return 0;
    if(dp[index][buy]!=-1)
    return dp[index][buy];

    int profit=0;
    if(buy){
    int Buy=-prices[index]+solveMem(index+1,0,prices,dp);
    int Skip=0+solveMem(index+1,buy,prices,dp);
    profit=max(Buy,Skip);
    }
    else{
    int Sale=prices[index]+solveMem(index+1,1,prices,dp);
    int Skip=0+solveMem(index+1,buy,prices,dp);
    profit=max(Sale,Skip);
    }
    return dp[index][buy]=profit;
}

int solveTab(vector<int>&prices){
    int n=prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2,0));

    for(int index=n-1;index>=0;index--){
    for(int buy=0;buy<=1;buy++){
        int profit=0;
        if(buy){
        int Buy=-prices[index]+dp[index+1][0];
        int Skip=0+dp[index+1][buy];
        profit=max(Buy,Skip);
        }
        else{
        int Sale=prices[index]+dp[index+1][1];
        int Skip=0+dp[index+1][buy];
        profit=max(Sale,Skip);
        }
        dp[index][buy]=profit;
        }
    }
return dp[0][1];
}

int solveOpt(vector<int>&prices){
    int n=prices.size();
    vector<int>curr(2,0);
    vector<int>next(2,0);

    for(int index=n-1;index>=0;index--){
    for(int buy=0;buy<=1;buy++){
        int profit=0;
        if(buy){
        int Buy=-prices[index]+next[0];
        int Skip=0+next[buy];
        profit=max(Buy,Skip);
        }
        else{
        int Sale=prices[index]+next[1];
        int Skip=0+next[buy];
        profit=max(Sale,Skip);
        }
        curr[buy]=profit;
        }
        next=curr;
    }
    return curr[1];
}

int maxProf(vector<int>&prices){
    // return solve(0,1,prices);

    // recursion + memorisation
    int n=prices.size();
    // vector<vector<int>>dp(n,vector<int>(2,-1));
    // return solveMem(0,1,prices,dp);

    // tabulation
    // return solveTab(prices);

    // space-optimisation
    return solveOpt(prices);
}

int main(){
    vector<int>prices={7,1,5,3,6,4};
    cout<<"Maximum profit for multiple buy and sale "<<maxProf(prices)<<endl;
    
    return 0;
}