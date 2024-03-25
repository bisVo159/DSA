#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<stack>
using namespace std;

void topoSort(int node,unordered_map<int,bool>&visited, stack<int>&s,unordered_map<int,list<int>>&adj){
    visited[node]=1;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour])
        topoSort(neighbour,visited,s,adj);
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>>&edges,int v,int e){
    //create adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    //call dfs toplogicalsort util function for all components
    unordered_map<int,bool>visited;
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!visited[i])
            topoSort(i,visited,s,adj);
    }
    vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
    return ans;
}

int main(){
    // ----->TOPOLOGICAL SORT USING DFS<-----
    vector<vector<int>>edges={{0,1},{1,2},{2,4},{4,5},{5,6},{4,6},{1,3},{3,4}};
    vector<int> TS=topologicalSort(edges,7,7);
    for(auto i:TS){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}