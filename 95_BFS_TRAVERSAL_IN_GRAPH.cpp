#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
#include<queue>
using namespace std;

void prepareAdjList( unordered_map<int,set<int>>&adjList,vector<pair<int,int>>&edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs( unordered_map<int,set<int>>adjList,  unordered_map<int,bool>&visited,vector<int>&ans,int node){
    queue<int>q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        //store frontNode into ans
        ans.push_back(frontNode);
        //traverse all neighbours of frontNode
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

vector<int> BFS(int vertex,vector<pair<int,int>>edges){
    unordered_map<int,set<int>>adjList;
    vector<int>ans;
    unordered_map<int,bool>visited;

    prepareAdjList(adjList,edges);
    //traverse all components of a graph
        for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}

int main(){
    // ----->BFS TRAVERSAL IN AN UNDIRECTED DISCONNECTED GRAPH<-----
    // vector<pair<int,int>>edges={{0,3},{3,1},{1,4},{1,2}};
    vector<pair<int,int>>edges={{0,3},{0,2},{3,1},{2,4},{1,4}};
    vector<int>ans=BFS(5,edges);
    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;
    
    return 0;
}