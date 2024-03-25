#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

void print(vector<int>&v,int j){
    if(j==0){
    cout<<v[j]<<endl;
    return;
    }

    for(int k=0;k<=j;k++)
        cout<<v[k]<<" ";
        cout<<endl;
    print(v,j/2);
}

bool subsequence(string &a,string &b,int i,int j){
    if(i==a.length())
    return true;
    if(i<a.length()&&j==b.length())
    return false;

    if(a[i]==b[j])
    return subsequence(a,b,i+1,j+1);
    else
    return subsequence(a,b,i,j+1);
}

int subsequence2(string a,string b){
    if(a.length()==0||b.length()==0)
    return 0;

    if(a[0]==b[0])
    return 1+subsequence2(a.substr(1),b.substr(1));
    else
    return subsequence2(a,b.substr(1));
}

int LIS(int a[],int curr,int size,int prev){
    if(curr==size)
    return 0;

    int include=0;
    if(a[curr]>a[prev]||prev==-1)
    include=1+LIS(a,curr+1,size,curr);

    int exclude=LIS(a,curr+1,size,prev);
    return max(include,exclude);
}

int LCS(string a,string b){
    if(a.length()==0||b.length()==0)
    return 0;

    if(a[0]==b[0])
     return 1+LCS(a.substr(1),b.substr(1));
    else
    return max(LCS(a.substr(1),b),LCS(a,b.substr(1)));
}

int solve(int a[],int i,int diff){
    if(i<0)
    return 0;

    int ans=0;
    for(int k=i-1;k>=0;k--){
        if(a[i]-a[k]==diff)
        return max(ans,1+solve(a,k,diff));
    }
    return ans;
}

int LAS(int a[],int size){
    int count=0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            count=max(count,2+solve(a,i,a[j]-a[i]));
        }
    }
    return count;
}

int main(){
    vector<int>v={3,4,1,5,6,2,7};
    // print(v,v.size()-1);

    // Find a is subsequence of b or not
    // string a="abc";
    // string b="ahbgdc";
    // cout<<subsequence(a,b,0,0)<<endl;
    // if(subsequence2(a,b)==a.length())
    // cout<<"a is b's subsequence"<<endl;
    // else
    // cout<<"a is not b's subsequence"<<endl;

    // Longest Increasing subsequence
    // int arr[]={0,1,0,3,2,3};
    // cout<<LIS(arr,0,6,-1)<<endl;

    // Longest common subsequence
    // string str1="abc";
    // string str2="def";
    // cout<<LCS(str1,str2)<<endl;

    // Longest arithmatic subsequence
    int a[]={9,4,7,2,10};
    cout<<LAS(a,5)<<endl;

    
    return 0;
}