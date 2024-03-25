#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&weight,vector<int>&value,int index,int capacity){
    //base case
    //if only 1 item to steal ,then just compare its weight with knapsack capacity
    if(index==0){
        if(weight[0]<=capacity)
        return value[0];
        else
        return 0;
    }

    int include=0;
    if(weight[index]<=capacity)
     include=value[index]+solve(weight,value,index-1,capacity-weight[index]);

     int exclude=solve(weight,value,index-1,capacity);

     int ans=max(include,exclude);
     return ans;
    }
int solveMem(vector<int>&weight,vector<int>&value,int index,int capacity, vector<vector<int>>&dp){
    if(index==0){
        if(weight[0]<=capacity)
        return value[0];
        else
        return 0;
    }

    if(dp[index][capacity]!=-1)
    return dp[index][capacity];
    
    int include=0;
    if(weight[index]<=capacity)
     include=solveMem(weight,value,index-1,capacity-weight[index],dp)+value[index];

     int exclude=solveMem(weight,value,index-1,capacity,dp);

     dp[index][capacity]=max(include,exclude);
     return dp[index][capacity];
    }

    int solveTab(vector<int>&weight,vector<int>&value,int n,int capacity){
        //step1:
      /*vector<vector<int>>dp(n,vector<int>(capacity+1,0));
        //step2: analyse base case
        for(int w=0;w<=capacity;w++){
            if(weight[0]<=capacity)
            dp[0][w]=value[0];
            else
            dp[0][w]=0;
        }

        for(int index=1;index<n;index++){
            for(int w=0;w<=capacity;w++){
                int include=0;
                if(weight[index]<=w)
                    include=value[index]+dp[index-1][w-weight[index]];
                    int exclude=dp[index-1][w];
                    dp[index][w]=max(exclude,include);
            }
        }
        return dp[n-1][capacity];*/

            //SPACE-OPTIMISATION
   /*vector<int>prev(capacity+1,0);
    vector<int>curr(capacity+1,0);

    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity)
        prev[w]=value[0];
        else
        prev[w]=0;
    }
    for(int index=1;index<n;index++){
        
            for(int w=0;w<=capacity;w++){
                int include=0;
                if(weight[index]<=w)
                    include=value[index]+prev[w-weight[index]];
                    int exclude=prev[w];
                   curr[w]=max(exclude,include);
            }
            prev=curr;
        }
        return prev[capacity];*/

    // Single array optimisation
    vector<int>curr(capacity+1,0);

    for(int w=0;w<=capacity;w++){
        if(weight[0]<=capacity)
        curr[w]=value[0];
        else
        curr[w]=0;
    }
    for(int index=1;index<n;index++){
        
            for(int w=capacity;w>=0;w--){
                int include=0;
                if(weight[index]<=w)
                    include=value[index]+curr[w-weight[index]];
                    int exclude=curr[w];
                   curr[w]=max(exclude,include);
            }
        }
        return curr[capacity];
    }

int knapSack(vector<int>weight,vector<int>value,int n,int maxWeight){
    //RECURSION
    // return solve(weight,value,n-1,maxWeight);

    //RECURSION + MEMORISATION
    // vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
    // return solveMem(weight,value,n-1,maxWeight,dp);

    //TABULATION
    return solveTab(weight,value,n,maxWeight);

}

int main(){
    vector<int>weight={1,2,4,5};
    vector<int>value={5,4,8,6};
    cout<<"Maximum value can be robbed "<<knapSack(weight,value,4,5)<<endl;

    return 0;
}