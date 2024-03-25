#include<iostream>
#include<vector>
using namespace std;

int solve1(int k,vector<int>&prices){
    int n=prices.size();
    vector<vector<int>>curr(2,vector<int>(k+1,0));
    vector<vector<int>>next(2,vector<int>(k+1,0));
    for(int index=n-1;index>=0;index--){
    for(int buy=0;buy<=1;buy++){
        for(int limit=1;limit<=k;limit++){
            int profit=0;
            if(buy){
            int Buy=-prices[index]+next[0][limit];
            int Skip=0+next[buy][limit];
            profit=max(Buy,Skip);
            }
            else{
            int Sale=prices[index]+next[1][limit-1];
            int Skip=0+next[buy][limit];
            profit=max(Sale,Skip);
            }
            curr[buy][limit]=profit;
        }
    }
    next=curr;
}
return curr[1][k];
}

// Transection method
int solve(int index,int operationsNo,int k,vector<int>&prices){
    if(index==prices.size())
    return 0;
    if(operationsNo==2*k)
    return 0;

    int profit=0;
    if(operationsNo%2==0){
        int Buy=-prices[index]+solve(index+1,operationsNo+1,k,prices);
        int  Skip=solve(index+1,operationsNo,k,prices);
        profit=max(Buy,Skip);
    }
    else{
        int Sale=prices[index]+solve(index+1,operationsNo+1,k,prices);
        int  Skip=solve(index+1,operationsNo,k,prices);
        profit=max(Sale,Skip);
    }
    return profit;
}
int solveMem(int index,int operationsNo,int k,vector<int>&prices,vector<vector<int>>&dp){
    if(index==prices.size())
    return 0;
    if(operationsNo==2*k)
    return 0;
    if(dp[index][operationsNo]!=-1)
    return dp[index][operationsNo];

    int profit=0;
    if(operationsNo%2==0){
        int Buy=-prices[index]+solveMem(index+1,operationsNo+1,k,prices,dp);
        int  Skip=solveMem(index+1,operationsNo,k,prices,dp);
        profit=max(Buy,Skip);
    }
    else{
        int Sale=prices[index]+solveMem(index+1,operationsNo+1,k,prices,dp);
        int  Skip=solveMem(index+1,operationsNo,k,prices,dp);
        profit=max(Sale,Skip);
    }
    return dp[index][operationsNo]=profit;
}

int solveTab(int k,vector<int>&prices){
    int n=prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
    for(int index=n-1;index>=0;index--){
        for(int operationsNo=2*k-1;operationsNo>=0;operationsNo--){
            int profit=0;
            if(operationsNo%2==0){
                int Buy=-prices[index]+dp[index+1][operationsNo+1];
                int  Skip=dp[index+1][operationsNo];
                profit=max(Buy,Skip);
            }
            else{
                int Sale=prices[index]+dp[index+1][operationsNo+1];
                int  Skip=dp[index+1][operationsNo];
                profit=max(Sale,Skip);
            }
            dp[index][operationsNo]=profit;
        }
    }
    return dp[0][0];
}
int solveOpt(int k,vector<int>&prices){
    int n=prices.size();
    vector<int>curr(2*k+1,0);
    vector<int>next(2*k+1,0);
    for(int index=n-1;index>=0;index--){
        for(int operationsNo=2*k-1;operationsNo>=0;operationsNo--){
            int profit=0;
            if(operationsNo%2==0){
                int Buy=-prices[index]+next[operationsNo+1];
                int  Skip=next[operationsNo];
                profit=max(Buy,Skip);
            }
            else{
                int Sale=prices[index]+next[operationsNo+1];
                int  Skip=next[operationsNo];
                profit=max(Sale,Skip);
            }
            curr[operationsNo]=profit;
        }
        next=curr;
    }
    return curr[0];
}

int maxProfit(int k,vector<int>&prices){
    // return solve1(k,prices);

    // return solve(0,0,k,prices);

    // recursion + memorisation
    // vector<vector<int>>dp(prices.size(),vector<int>(2*k,-1));
    // return solveMem(0,0,k,prices,dp);

    // tabulation
    // return solveTab(k,prices);

    // space-optimisation
    return solveOpt(k,prices);

}

int main(){
    vector<int>prices={3,2,6,5,0,3};
    // vector<int>prices={1,2,3,4,5};
    // vector<int>prices={2,4,1};
    int k=3;
    cout<<"Maximum profit for at most "<<k<<" transection "<<maxProfit(k,prices)<<endl;
    return 0;
}