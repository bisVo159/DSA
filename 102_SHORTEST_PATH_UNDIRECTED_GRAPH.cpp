#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>>edges,int n,int s,int t){
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //do bfs
    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;
    queue<int>q;
    q.push(s);
    visited[s]=1;
    parent[s]=-1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i:adj[front]){
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
                parent[i]=front;
            }
        }
    }
    //prepare shortest path
    vector<int>ans;
    int dest=t;
    ans.push_back(dest);
    while(dest!=s){
        dest=parent[dest];
        ans.push_back(dest);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    // ----->SHORTEST PATH IN UNDIRECTED GRAPH USING BFS<-----
    vector<pair<int,int>>edges={{1,2},{2,5},{5,8},{1,3},{3,8},{1,4},{4,6},{6,7},{7,8}};
    vector<int>shortest=shortestPath(edges,8,1,8);
    for(int i=0;i<shortest.size();i++)
    cout<<shortest[i]<<" ";
    cout<<endl;
    
    return 0;
}