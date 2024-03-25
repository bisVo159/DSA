#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int solve(vector<int>&satisfaction,int index,int time){
    if(index==satisfaction.size())
    return 0;

    int include=(time+1)*satisfaction[index]+solve(satisfaction,index+1,time+1);
    int exclude=solve(satisfaction,index+1,time);
    return max(include,exclude);
}
int solveMem(vector<int>&satisfaction,int index,int time,vector<vector<int>>&dp){
    if(index==satisfaction.size())
    return 0;
    if(dp[index][time]!=-1)
    return dp[index][time];

    int include=(time+1)*satisfaction[index]+solveMem(satisfaction,index+1,time+1,dp);
    int exclude=solveMem(satisfaction,index+1,time,dp);
    return dp[index][time]=max(include,exclude);
}
int solveTab(vector<int>&satisfaction){
    int n=satisfaction.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int index=n-1;index>=0;index--){
        for(int time=index;time>=0;time--){
                int include=(time+1)*satisfaction[index]+dp[index+1][time+1];
                int exclude=dp[index+1][time];
                 dp[index][time]=max(include,exclude);
        }
    }
    return dp[0][0];
}


int maxSatisfaction(vector<int>&satisfaction){
    sort(satisfaction.begin(),satisfaction.end());
    // return solve(satisfaction,0,0);

    // recursion + memorisation
    int n=satisfaction.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    // return solveMem(satisfaction,0,0,dp);

    // tabulation
    // return solveTab(satisfaction);
    
    // space-optimisation
    vector<int>next(n+1,0);
    vector<int>curr(n+1,0);

    for(int index=n-1;index>=0;index--){
        for(int time=index;time>=0;time--){
                int include=(time+1)*satisfaction[index]+next[time+1];
                int exclude=next[time];
                 curr[time]=max(include,exclude);
        }
        next=curr;
    }
    return next[0];
}

int main(){
    vector<int>satisfaction={-1,-8,0,5,-9};
    cout<<"Maximum sum of like-time-coefficient "<<maxSatisfaction(satisfaction)<<endl;

    // HW: convert into O(1) space optimisation using greedy algorithm
    
    return 0;
}