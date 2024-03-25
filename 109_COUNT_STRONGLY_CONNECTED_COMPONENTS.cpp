#include<bits/stdc++.h>
using namespace std;

void dfs(int node,unordered_map<int,bool>&vis,stack<int>&st,unordered_map<int,list<int>>&adj){
    vis[node]=1;
    for(auto nbr:adj[node]){
        if(!vis[nbr]){
            dfs(nbr,vis,st,adj);
        }
    }
    st.push(node);
}

void revDfs(int node,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj){
        vis[node]=1;
    for(auto nbr:adj[node]){
        if(!vis[nbr]){
            revDfs(nbr,vis,adj);
        }
    }
}

int stronglyConnectedComponents(int v,vector<vector<int>>&edges){
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    // topo sort
    stack<int>st;
    unordered_map<int,bool>vis;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    // create transpose
    unordered_map<int,list<int>>transpose;
    for(int i=0;i<v;i++){
        vis[i]=0;
        for(auto j:adj[i]){
            transpose[j].push_back(i);
        }
    }
    //dfs call using above ordering
    int count=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(!vis[top]){
            count++;
            revDfs(top,vis,transpose);
        }
    }
    return count;
}

int main(){
    // ----->KOSARAJU'S ALGORITHM<-----
    vector<vector<int>>edges={{2,0},{0,1},{1,2},{1,3},{3,4}};
    cout<<"Total number of strongly connected components are "<<stronglyConnectedComponents(5,edges)<<endl;
    return 0;
}