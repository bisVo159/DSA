#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;

int solve(vector<int>&arr,map<pair<int,int>,int>maxi,int left,int right){
    // leaf node
    if(left==right)
    return 0;

    int ans=INT_MAX;
    for(int i=left;i<right;i++){
        ans=min(ans,maxi[{left,i}]*maxi[{i+1,right}] + solve(arr,maxi,left,i) + solve(arr,maxi,i+1,right));
    }
    return ans;
}
int solveMem(vector<int>&arr,map<pair<int,int>,int>maxi,int left,int right,vector<vector<int>>&dp){
    // leaf node
    if(left==right)
    return 0;
    if(dp[left][right]!=-1)
    return dp[left][right];

    int ans=INT_MAX;
    for(int i=left;i<right;i++){
        ans=min(ans,maxi[{left,i}]*maxi[{i+1,right}] + solveMem(arr,maxi,left,i,dp) + solveMem(arr,maxi,i+1,right,dp));
    }
    return dp[left][right]=ans;
}

int mctFromLeafValue(vector<int>&arr){
 map<pair<int,int>,int>maxi;
 for(int i=0;i<arr.size();i++){
    maxi[{i,i}]=arr[i];
    for(int j=i+1;j<arr.size();j++){
        maxi[{i,j}]=max(maxi[{i,j-1}],arr[j]);
    }
 }
//  return solve(arr,maxi,0,arr.size()-1);

// recursion + memorisation
vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
return solveMem(arr,maxi,0,arr.size()-1,dp);
}

int main(){
    vector<int>arr={6,2,4};
    cout<<"Maximum cost tree from leaf tree "<<mctFromLeafValue(arr)<<endl;

    // H.W: solve tabulation method
    
    return 0;
}