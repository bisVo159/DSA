#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int>> celculatePrimsMST(int n,int m,vector<pair<pair<int,int>,int>>&edges){
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<m;i++){
        int u=edges[i].first.first;
        int v=edges[i].first.second;
        int w=edges[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int>key(n+1,INT_MAX);
    vector<bool>mst(n+1,false);
    vector<int>parent(n+1,-1);
    key[1]=0;

    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        int u;
        //find min wali node
        for(int v=1;v<=n;v++){
            if(key[v]<mini&&mst[v]!=true){
                 u=v;
                mini=key[v];
            }
        }
        //mark min node as true
        mst[u]=true;
        //check its adjacent nodes
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false&&key[v]>w){
                parent[v]=u;
                key[v]=w;
            }
        }
    }
    vector<pair<pair<int,int>,int>>result;
    for(int i=2;i<=n;i++){
        result.push_back({{parent[i],i},key[i]});
    }
    return result;
}

int main(){
    // ----->MINIMUM SPANNING TREE<-----
    vector<pair<pair<int,int>,int>>g={{{0,1},2},{{0,3},6},{{1,3},8},{{1,4},5},{{1,2},3},{{2,4},7}};
    vector<pair<pair<int,int>,int>>result=celculatePrimsMST(5,6,g);

    return 0;
}