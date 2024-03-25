#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

void dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,set<int>>&adj, vector<int>&component){
    component.push_back(node);
    visited[node]=true;
    //hr connected node l liye recursive call
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,visited,adj,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V,vector<vector<int>>&edges){
    unordered_map<int,set<int>>adj;
    //prepare adj list
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<vector<int>>ans;
    unordered_map<int,bool>visited;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int>component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main(){
    // ----->DFS TRAVERSAL IN AN UNDIRECTED DISCONNECTED GRAPH<-----
    vector<vector<int>>edges={{0,2},{2,1},{1,3},{3,4},{4,2},{5,6},{6,7},{5,7}};    //disconnected graph
    // vector<vector<int>>edges={{0,3},{3,1},{1,4},{4,2},{2,0}};    //connected graph
    vector<vector<int>>dfs=depthFirstSearch(8,edges);
    for(auto i:dfs){
        for(auto j:i){
            cout<<j<<" ";
        }
    }cout<<endl;
    
    return 0;
}