#include<iostream>
#include<vector>
using namespace std;

long long int solveMem(int n,vector<long long int>&dp){
    //base case
    if(n==1)
    return 0;
     if(n==2)
    return 1;
    if(dp[n]!=-1)
    return dp[n];

    dp[n]=(n-1)*(solveMem(n-1,dp)+solveMem(n-2,dp));
    return dp[n];
}
long long int solveTab(int n){
    vector<long long int>dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}

long long int countDerangement(int n){
    //recursion + memorisation
    // vector<long long int>dp(n+1,-1);
    // return solveMem(n,dp);

    //Tabulation
    return solveTab(n);
}

int main(){
    int n=5;
    cout<<"Total number of possible derangement of "<<n<<" : "<<countDerangement(n)<<endl;
    
    // ----->spaceOptimisation<-----
    long long int prev2=0;
    long long int prev1=1;
    for(int i=3;i<=n;i++){
        long long int ans=(i-1)*(prev2+prev1);
        prev2=prev1;
        prev1=ans;
    }
    cout<<"Total number of possible derangement of "<<n<<" : "<<prev1<<endl;
    return 0;
}