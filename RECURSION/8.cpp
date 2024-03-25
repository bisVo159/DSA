#include<iostream>
#include<vector>
using namespace std;

int solve(int n,int k){
    if(n==1)
    return k;
    if(n==2)
    return k*(k-1)+k;

    int same=solve(n-2,k)*(k-1);
    int diff=solve(n-1,k)*(k-1);
    return same+diff;
}

    int solve(vector<int>& slices,int s,int e,int n){
        if(n==0||s>e)
        return 0;

        int include=slices[s]+solve(slices,s+2,e,n-1);
        int exclude=solve(slices,s+1,e,n);
        return max(include,exclude);
    }
    int maxSizeSlices(vector<int>& slices) {
        
        int totalslices=slices.size();
        int opt1=solve(slices,0,totalslices-2,totalslices/3);
        int opt2=solve(slices,1,totalslices-1,totalslices/3);
        return max(opt1,opt2);
    }

int main(){
    // Painting Fence
    // int n=5;
    // int k=3;
    // int ans=solve(n,k);
    // cout<<"ans is "<<ans<<endl;

    // Pizza with 3n slices
    vector<int>slices={1,2,3,4,5,6};
    cout<<maxSizeSlices(slices)<<endl;

    
    return 0;
}