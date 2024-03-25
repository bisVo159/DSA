#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(vector<int>base,vector<int>newBox){
    return base[0]>=newBox[0]&&base[1]>=newBox[1]&&base[2]>=newBox[2];
}

int solveTab(int n,vector<vector<int>>&a){
    vector<int>nextRow(n+1,0);
    vector<int>currRow(n+1,0);
    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
            int take=0;
            if(prev==-1||check(a[curr],a[prev]))
            take=a[curr][2]+nextRow[curr+1];
            int notTake=nextRow[prev+1];
            currRow[prev+1]=max(take,notTake);
        }
        nextRow=currRow;
    }
    return nextRow[0];
}

int maxHeight(vector<vector<int>>&cuboids){
    // step1: sort all dimensions for evry cuboids
    for(auto &a:cuboids){
        sort(a.begin(),a.end());
    }
    // step2: sort all cuboids basis on w or l
    sort(cuboids.begin(),cuboids.end());
    // step3:use LIS logic
    return solveTab(cuboids.size(),cuboids);

}

int main(){
    vector<vector<int>>cuboids={{50,45,20},{95,37,53},{45,23,12}};
    cout<<"Maximum height obtained by these cuboids "<<maxHeight(cuboids)<<endl;
    
    return 0;
}