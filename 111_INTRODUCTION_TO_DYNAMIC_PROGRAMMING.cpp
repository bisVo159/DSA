#include<iostream>
#include<vector>
using namespace std;

int fib(int n,vector<int>&dp){
    if(n<=1)
    return n;
    // step3
    if(dp[n]!=-1)
    return dp[n];

    // step2
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}

int main(){
    // ----->Nth FIBONACCI NUMBER<-----
    int n;
    cin>>n;
    // step1
    vector<int>dp(n+1,-1);
    cout<<"Nth fibonacci number "<<fib(n,dp)<<endl;
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<"Nth fibonacci number "<<dp[n]<<endl;

    int prev1=0;
    int prev2=1;
    int curr;
    for(int i=2;i<=n;i++){
        curr= prev2+prev1;
        prev1=prev2;
        prev2=curr;
    }
    cout<<"Nth fibonacci number "<<prev2<<endl;
    return 0;
}