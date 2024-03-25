#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSafe(int x,int y,int n,vector<vector<int>>visited,vector<vector<int>>&m){
    if((x>=0&&x<n)&&(y>=0&&y<n)&&visited[x][y]==0&&m[x][y]==1){
        return true;
    }
    else 
    return false;
}

void solve(vector<vector<int>>&m,int n,vector<string>&ans,int x,int y,vector<vector<int>>visited,string path){
//base case
if((x==n-1)&&(y==n-1)){
    ans.push_back(path);
    return;
}
visited[x][y]=1;
//4 choices - D L R U
//down

if(isSafe(x+1,y,n,visited,m)){
     path.push_back('D');
     solve(m,n,ans,x+1,y,visited,path);
     path.pop_back();
}
//Left
if(isSafe(x,y-1,n,visited,m)){
     path.push_back('L');
     solve(m,n,ans,x,y-1,visited,path);
     path.pop_back();
}
//Right
if(isSafe(x,y+1,n,visited,m)){
     path.push_back('R');
     solve(m,n,ans,x,y+1,visited,path);
     path.pop_back();
}
//Upper
if(isSafe(x-1,y,n,visited,m)){
     path.push_back('U');
     solve(m,n,ans,x-1,y,visited,path);
     path.pop_back();
}
visited[x][y]==0;
}

int main(){
    vector<string>ans;
    vector<vector<int>>m={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    int n;
    cin>>n;
    int srcx=0;
    int srcy=0;
    vector<vector<int>>visited={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    //initialise with zero
   /* for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }*/
    string path="";
    solve(m,n,ans,srcx,srcy,visited,path);
    sort(ans.begin(),ans.end());
    for(auto ele:ans)
    cout<<ele<<" ";
    return 0;
}