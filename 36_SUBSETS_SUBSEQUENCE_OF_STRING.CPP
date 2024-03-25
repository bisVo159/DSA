#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>subsets;

void solve(vector<int>&nums,vector<int>&output,int index){
     if(index==nums.size()){
    /* for(int i=0;i<output.size();i++)
     cout<<output[i]<<" ";
     cout<<endl;*/
     subsets.push_back(output);
     return;
     }
     //exclude
     solve(nums,output,index+1);
     //include
     int element=nums[index];
     output.push_back(element);
    solve(nums,output,index+1);
    output.pop_back();
}

void subsequences(string str,string output,int index,vector<string>&ans){
         if(index==str.length()){
            ans.push_back(output);
            return;
         }
         subsequences(str,output,index+1,ans);
         char element=str[index];
         output.push_back(element);
         subsequences(str,output,index+1,ans);
         output.pop_back();
}

int main(){
    //------>SUBSETS OF A GIVEN ARRAY<------
   /* vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
  // vector<vector<int>>ans;
   vector<int>output;
   int index=0;
   solve(nums,output,index);
for(auto output:subsets){
    for(auto ele:output)
    cout<<ele<<" ";
    cout<<endl;
}*/

//------>SUBSEQUENCES OF A STRING<------
 /* string str="abc";
  string output="";
  int index=0;
  vector<string>ans;
  subsequences(str,output,index,ans);
  for(auto ele:ans)
  cout<<ele<<" "<<endl;*/

    return 0;
}