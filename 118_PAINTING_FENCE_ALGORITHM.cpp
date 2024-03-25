#include<iostream>
#include<vector>
using namespace std;

int solve(int n,int k){
    if(n==1)
    return k;
    if(n==2)
    return k+k*(k-1);

    int ans=solve(n-2,k)*(k-1)+solve(n-1,k)*(k-1);
    return ans;
}
int solveMem(int n,int k,vector<int>&dp){
    if(n==1)
    return k;
    if(n==2)
    return k+k*(k-1);
    if(dp[n]!=-1)
    return dp[n];

    dp[n]=solveMem(n-2,k,dp)*(k-1)+solveMem(n-1,k,dp)*(k-1);
    return dp[n];
}

int solveTab(int n,int k){
    vector<int>dp(n+1);
    dp[1]=k;
    dp[2]=k+k*(k-1);
    for(int i=3;i<=n;i++){
        dp[i]=(k-1)*dp[i-1]+(k-1)*dp[i-2];
    }
    return dp[n];
}

int numberOfWays(int n,int k){
    //recursion
    // return solve(n,k);

    //recursion + memorisation
    // vector<int>dp(n+1,-1);
    // return solveMem(n,k,dp);

    //Tabulation
    return solveTab(n,k);
}

int main(){
    // ----->NINJA AND FENCE PROBLEM<-----
    int n=3,k=3;
    cout<<"Number of ways to print "<<n<<" post with "<<k<<" color "<<numberOfWays(n,k)<<endl;

    // ----->SPACE-OPTIMISATION<-----
    int prev2=k;
    int prev1=k+k*(k-1);
    for(int i=3;i<=n;i++){
        int ans=prev2*(k-1)+prev1*(k-1);
        prev2=prev1;
        prev1=ans;
    }
    cout<<"Number of ways to print "<<n<<" post with "<<k<<" color "<<prev1<<endl;
    
    return 0;
}