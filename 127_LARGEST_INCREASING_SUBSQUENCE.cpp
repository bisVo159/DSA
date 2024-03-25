#include<iostream>
#include<vector>
using namespace std;

int solve(int n,int a[],int curr,int prev){
    if(curr==n)
    return 0;

    // include
    int take=0;
    if(prev==-1||a[curr]>a[prev])
         take=1+solve(n,a,curr+1,curr);
         
    // exclude
    int notTake=solve(n,a,curr+1,prev);

    return max(take,notTake);
}
int solveMem(int n,int a[],int curr,int prev,vector<vector<int>>&dp){
    if(curr==n)
    return 0;
    if(dp[curr][prev+1]!=-1)
    return dp[curr][prev+1];

    // include
    int take=0;
    if(prev==-1||a[curr]>a[prev])
         take=1+solveMem(n,a,curr+1,curr,dp);
         
    // exclude
    int notTake=solveMem(n,a,curr+1,prev,dp);

    return dp[curr][prev+1]=max(take,notTake);
}

int solveTab(int n,int a[]){
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
            int take=0;
            if(prev==-1||a[curr]>a[prev])
            take=1+dp[curr+1][curr+1];
            int notTake=dp[curr+1][prev+1];
            dp[curr][prev+1]=max(take,notTake);
        }
    }
    return dp[0][0];
}

int solveOptimal(int n,int a[]){
    if(n==0)
    return 0;

    vector<int>ans;
    ans.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]>ans.back())
        ans.push_back(a[i]);
        else{
            // find index of just bada element in ans
            int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
            ans[index]=a[i];
        }
    }
    return ans.size();
}

int longestSubsequence(int n,int a[]){
    // return solve(n,a,0,-1);

    // recursion + memorisation
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // return solveMem(n,a,0,-1,dp);

    // tabulation
    // return solveTab(n,a);

    // space-optimisation
    vector<int>nextRow(n+1,0);
    vector<int>currRow(n+1,0);
    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
            int take=0;
            if(prev==-1||a[curr]>a[prev])
            take=1+nextRow[curr+1];
            int notTake=nextRow[prev+1];
            currRow[prev+1]=max(take,notTake);
        }
        nextRow=currRow;
    }
    return nextRow[0];
}

int main(){
    int a[]={5,8,3,7,9,1};
    int b[]={5,8,7,9,1,2,3,4};
    cout<<"Largest increasing subsequence length "<<longestSubsequence(8,b)<<endl;
    cout<<"Largest increasing subsequence length "<<solveOptimal(8,b)<<endl;   //T.C: O(nlog(n))
    
    return 0;
}