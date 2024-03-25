#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

bool checkCycleDFS(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,unordered_map<int,list<int>>&adj){
    visited[node]=true;
    dfsVisited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
         bool checkcycle=checkCycleDFS(neighbour,visited,dfsVisited,adj);
         if(checkcycle)
         return true;
        }
        else if(dfsVisited[neighbour]==true)
        return true;
    }
    dfsVisited[node]=false;
    return false;
}

int detectCycleInDirectedGraph(int n,vector<pair<int,int>>&edges){
    // create adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        //directed graph
        adj[u].push_back(v);
    }
    //call dfs for all components
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsVisited;
    for(int i=1;i<n;i++){
        if(!visited[i]){
            bool cycleFound=checkCycleDFS(i,visited,dfsVisited,adj);
            if(cycleFound)
            return true;
        }
    }
    return false;
}

int main(){
    // ----->CYCLE DETECTION IN DIRECTED GRAPH USING DFS<-----
    vector<pair<int,int>> edges={{1,2},{2,3},{3,7},{3,8},{8,7},{3,4},{4,5},{5,6},{6,4}};
    int cycleFound=detectCycleInDirectedGraph(8,edges);
    if(cycleFound)
    cout<<"Cycle Found"<<endl;
    else
    cout<<"Cycle not found"<<endl;
    
    return 0;
}