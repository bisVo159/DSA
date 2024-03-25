#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

bool iscyclicBFS(int src,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj){
    unordered_map<int,int>parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour:adj[front]){
            if(visited[neighbour]==true&&neighbour!=parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=true;
                parent[neighbour]=front;
            }
        }
    }
    return false;
}

bool iscyclicDFS(int node,int parent,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj){
    visited[node]=true;
    for(auto neighbour:adj[node]){
     if(!visited[neighbour]){
        bool cycleDetected=iscyclicDFS(neighbour,node,visited,adj);
        if(cycleDetected)
        return true;
     }
    else if(neighbour!=parent){
        //cycle present
        return true;
        }
    }
     return false;
}

string cycleDetection(vector<vector<int>>&edges,int n,int m){
    //create adjacency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //to handle disconnected components
    unordered_map<int,bool>visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            // bool ans= iscyclicBFS(i,visited,adj);
            bool ans= iscyclicDFS(i,-1,visited,adj);
            if(ans==1)
            return "Yes";
        }
    }
    return "No";
}

int main(){
    // ------>CYCLE DETECTION IN UNORDERED GRAPH USING BFS<-----
    vector<vector<int>> edges={{0,1},{1,2},{2,3},{4,5},{5,6},{5,7},{6,8},{7,8},{8,9}};     //cycle present
    // vector<vector<int>> edges={{0,1},{1,2},{2,3},{4,5},{5,6},{6,8},{7,8},{8,9}};     //cycle not present
    cout<<cycleDetection(edges,10,9)<<endl;
    
    return 0;
}