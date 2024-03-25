#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(vector<int>&num1,vector<int>&num2,int index,bool swapped){
    //base case
    if(index==num1.size())
    return 0;

    int ans=INT_MAX;
    int prev1=num1[index-1];
    int prev2=num2[index-1];

    //catch
    if(swapped)
    swap(prev1,prev2);

    //noswap
    if(num1[index]>prev1&&num2[index]>prev2)
    ans=solve(num1,num2,index+1,0);

    // swap
    if(num1[index]>prev2&&num2[index]>prev1)
    ans=min(ans,1+solve(num1,num2,index+1,1));
    return ans;
}
int solveMem(vector<int>&num1,vector<int>&num2,int index,bool swapped,vector<vector<int>>&dp){
    //base case
    if(index==num1.size())
    return 0;
    if(dp[index][swapped]!=-1)
    return dp[index][swapped];

    int ans=INT_MAX;
    int prev1=num1[index-1];
    int prev2=num2[index-1];

    //catch
    if(swapped)
    swap(prev1,prev2);

    //noswap
    if(num1[index]>prev1&&num2[index]>prev2)
    ans=solveMem(num1,num2,index+1,0,dp);

    // swap
    if(num1[index]>prev2&&num2[index]>prev1)
    ans=min(ans,1+solveMem(num1,num2,index+1,1,dp));
    return dp[index][swapped]=ans;
}
int solveTab(vector<int>&num1,vector<int>&num2){
    int n=num1.size();
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    for(int index=n-1;index>=1;index--){
        for(int swapped=1;swapped>=0;swapped--){
            int ans=INT_MAX;
            int prev1=num1[index-1];
            int prev2=num2[index-1];

            //catch
            if(swapped)
            swap(prev1,prev2);

            //noswap
            if(num1[index]>prev1&&num2[index]>prev2)
            ans=dp[index+1][0];

            // swap
            if(num1[index]>prev2&&num2[index]>prev1)
            ans=min(ans,1+dp[index+1][1]);
            dp[index][swapped]=ans;
        }
    }
    return dp[1][0];
}
int solveOpt(vector<int>&num1,vector<int>&num2){
    int n=num1.size();
    int Swap=0;
    int noSwap=0;
    int currSwap,currNoSwap;
    for(int index=n-1;index>=1;index--){
        for(int swapped=1;swapped>=0;swapped--){
            int ans=INT_MAX;
            int prev1=num1[index-1];
            int prev2=num2[index-1];

            //catch
            if(swapped)
            swap(prev1,prev2);

            //noswap
            if(num1[index]>prev1&&num2[index]>prev2)
            ans=noSwap;

            // swap
            if(num1[index]>prev2&&num2[index]>prev1)
            ans=min(ans,1+Swap);
            if(swapped)
                 currSwap=ans;
            else
                 currNoSwap=ans;
        }
        Swap=currSwap;
        noSwap=currNoSwap;
    }
    return min(Swap,noSwap);
}


int minSwap(vector<int>&num1,vector<int>&num2){
    num1.insert(num1.begin(),-1);
    num2.insert(num2.begin(),-1);
    // it means that the previous index were swapped or not
    bool swapped=0;
    // return solve(num1,num2,1,swapped);

    // recursion+memorisation
    vector<vector<int>>dp(num1.size(),vector<int>(2,-1));
    // return solveMem(num1,num2,1,swapped,dp);

    // tabulation
    return solveTab(num1,num2);

    // space-optimisation
    return solveOpt(num1,num2);
}

int main(){
    vector<int>nums1={1,2,5,4};
    vector<int>nums2={1,3,3,7};
    cout<<"Minimum number of swap to make 2 sequence strictly increasing "<<minSwap(nums1,nums2)<<endl;
    
    return 0;
}