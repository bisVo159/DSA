#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>nums,vector<vector<int>>&ans,int index){
     if(index==nums.size()){
        ans.push_back(nums);
        return;
     }
     for(int j=index;j<nums.size();j++){
        swap(nums[index],nums[j]);
        solve(nums,ans,index+1);
        swap(nums[index],nums[j]);
     }
}

void permutations(string str,int index,vector<string>&ans){
   if(index==str.length()){
      ans.push_back(str);
      return;
   }
   for(int j=index;j<str.length();j++){
       swap(str[index],str[j]);
       permutations(str,index+1,ans);
       swap(str[index],str[j]);
   }
}


int main(){
  //------>PERMUTATION OF AN ARRAY<------
 /*vector<vector<int>>ans;
 vector<int>nums={1,2,3};*/
/* nums.push_back(1);
 nums.push_back(2);
 nums.push_back(3);*/
 /*int index=0;
 solve(nums,ans,index);
 for(auto nums:ans){
    for(auto ele:nums){
        cout<<ele;
    }cout<<endl;
 }*/
 string str="abc";
 vector<string>ans;
 int index=0;
 permutations(str,index,ans);
 for(auto nums:ans){
    for(auto ele:nums){
        cout<<ele;
    }cout<<endl;
 }
}