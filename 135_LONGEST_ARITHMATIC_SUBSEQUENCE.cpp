#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int longestSubsquence(vector<int>&arr,int difference){
    int n=arr.size();
    unordered_map<int,int>dp;
    int ans=0;
    for(int i=0;i<n;i++){
        int temp=arr[i]-difference;
        int tempAns=0;
        if(dp.count(temp))
        tempAns=dp[temp];

        dp[arr[i]]=1+tempAns;
        ans=max(ans,dp[arr[i]]);
    }
    return ans;
}

int main(){
    vector<int>arr={1,5,7,8,5,3,4,2,1};
    cout<<"Longest Arithmatic subsquence with given difference "<<longestSubsquence(arr,-2)<<endl;
    
    return 0;
}