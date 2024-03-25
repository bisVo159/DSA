#include<iostream>
#include<vector>
using namespace std;

int lastRemaining(int n){
    if(n==1)
    return 1;
    return 2*(1+n/2-lastRemaining(n/2));
}

int solve(vector<int>&a,int i,int j){
    if(i>j)
    return 0;
    if(i==j)
    return a[i];

    int option1=a[i]+min(solve(a,i+2,j),solve(a,i+1,j-1));
    int option2=a[j]+min(solve(a,i+1,j-1),solve(a,i,j-2));

    return max(option1,option2);
}

int main(){
    // Elimination Game
    // cout<<lastRemaining(7)<<endl;

    // Predict the winner
    vector<int>nums={5,2,4,7,6};
     int total=0;
        for(auto i:nums)
        total+=i;

        int point1=solve(nums,0,nums.size()-1);
        int point2=total-point1;
        if(point1>point2)
        cout<<"Player 1 win"<<endl;
        else
        cout<<"Player 2 win"<<endl;
    
    return 0;
}