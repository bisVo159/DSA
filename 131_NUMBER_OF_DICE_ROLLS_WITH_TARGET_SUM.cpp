#include<iostream>
#include<vector>
using namespace std;

int solve(int dice,int faces,int target){
    //base case
    if(target<0)
    return 0;
    if(dice==0&&target!=0)
    return 0;
    if(dice!=0&&target==0)
    return 0;
    if(dice==0&&target==0)
    return 1;

    int ans=0;
    for(int i=1;i<=faces;i++){
        ans=ans+solve(dice-1,faces,target-i);
    }
    return ans;
}
int solveMem(int dice,int faces,int target,vector<vector<int>>&dp){
    //base case
    if(target<0)
    return 0;
    if(dice==0&&target!=0)
    return 0;
    if(dice!=0&&target==0)
    return 0;
    if(dice==0&&target==0)
    return 1;
    if(dp[dice][target]!=-1)
    return dp[dice][target];

    int ans=0;
    for(int i=1;i<=faces;i++){
        ans=ans+solveMem(dice-1,faces,target-i,dp);
    }
    return dp[dice][target]= ans;
}
int solveTab(int d,int f,int t){
    vector<vector<int>>dp(d+1,vector<int>(t+1,0));
    dp[0][0]=1;

    for(int dice=1;dice<=d;dice++){
        for(int target=1;target<=t;target++){
                for(int i=1;i<=f;i++){
                    if(target-i>=0)
                    dp[dice][target]=dp[dice][target]+dp[dice-1][target-i];
                }
        }
    }
    return dp[d][t];
}
int solveOpt(int d,int f,int t){
    vector<int>curr(t+1,0);
    vector<int>prev(t+1,0);
    prev[0]=1;
    for(int dice=1;dice<=d;dice++){
        for(int target=1;target<=t;target++){
            int ans=0;
                for(int i=1;i<=f;i++){
                    if(target-i>=0)
                    ans=ans+prev[target-i];
                }
                curr[target]=ans;
        }
        prev=curr;
    }
    return curr[t];
}

int noOfWays(int M,int N,int X){
    // return solve(N,M,X);

    // recursion + memorisation
    // vector<vector<int>>dp(N+1,vector<int>(X+1,-1));
    // return solveMem(N,M,X,dp);

    // tabulation
    // return solveTab(N,M,X);

    // space-optimisation
    return solveOpt(N,M,X);
}

int main(){
    cout<<noOfWays(6,3,12)<<endl;
    
    return 0;
}