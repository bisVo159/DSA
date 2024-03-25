#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;

int detectCycleInDirectedGraph(int n,vector<pair<int,int>>&edges){
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
    }
    vector<int>indegree(n+1);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();
    //inc cnt
    cnt++;
    //neighbour indegree update
    for(auto neighbour:adj[front]){
        indegree[neighbour]--;
        if(indegree[neighbour]==0)
        q.push(neighbour);
        }
    }
    if(cnt==n)
    return false;
    else
    return true;
}

int main(){
    // ----->CYCLE DETECTION IN DIRECTED GRAPH USING BFS<-----
        // vector<pair<int,int>>edges={{1,2},{1,3},{2,5},{3,5},{5,4}};    //cycle not present
        vector<pair<int,int>>edges={{1,2},{3,1},{2,5},{5,3},{5,4}};        //cycle present
    if(detectCycleInDirectedGraph(5,edges))
    cout<<"Cycle Present"<<endl;
    else
    cout<<"Cycle not present"<<endl;

    
    return 0;
}