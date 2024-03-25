#include<iostream>
#include<vector>
using namespace std;

int solveTab(vector<int>&nums){
    int incl,excl;
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        if(i-2<0)
         incl=0+nums[i];
        else
         incl=dp[i-2]+nums[i];

         excl=dp[i-1];
        dp[i]=max(incl,excl);
    }
    return dp[n-1];
}

int houseRobber(vector<int>&valueInHouse){
    int n=valueInHouse.size();
    if(n==1)
    return valueInHouse[0];

vector<int> first,second;
for(int i=0;i<n;i++){
    if(i!=n-1)
    first.push_back(valueInHouse[i]);
    if(i!=0)
    second.push_back(valueInHouse[i]);
}
    return max(solveTab(first),solveTab(second));
}

int main(){
    vector<int>value={5,3,2,7};
    cout<<"Maximum money stolen "<<houseRobber(value)<<endl;
    
    return 0;
}