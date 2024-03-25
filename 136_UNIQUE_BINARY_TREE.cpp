#include<iostream>
#include<vector>
using namespace std;

int solve(int n,vector<int>&dp){
    if(n==0||n==1)
    return 1;
    if(dp[n]!=-1)
    return dp[n];

    int ans=0;
    // think i as root node
    for(int i=1;i<=n;i++){
         ans+=solve(i-1,dp)*solve(n-i,dp);
    }
    return dp[n]=ans;
}

int solveTab(int n){
    vector<int>dp(n+1,0);
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
    // i->number of nodes
    for(int j=1;j<=i;j++)
        // j->root node
         dp[i]+=dp[j-1]*dp[i-j];
    }
    return dp[n];
}

int numTrees(int n){
    if(n==0||n==1)
    return 1;

    int ans=0;
    // think i as root node
    for(int i=1;i<=n;i++){
         ans+=numTrees(i-1)*numTrees(n-i);
    }
    return ans;
}

int main(){
    // catalan number->same solution     Cn=[1/(n+1)*(2nCn)]
    int n;
    cout<<"Enter number of nodes"<<endl;
    cin>>n;
    // cout<<"Number of unique BST for "<<n<<" nodes "<<numTrees(n)<<endl;

    // recursion + memorisation
    vector<int>dp(n+1,-1);
    // cout<<"Number of unique BST for "<<n<<" nodes "<<solve(n,dp)<<endl;

    // tabulation
    cout<<"Number of unique BST for "<<n<<" nodes "<<solveTab(n)<<endl;
    
    return 0;
}