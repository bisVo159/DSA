#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}

void makeSet(vector<int>&parent, vector<int>&rank,int n){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int findParent(vector<int>&parent,int node){
    if(parent[node]==node)
    return node;
    return parent[node]=findParent(parent,parent[node]);
}

void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
    u=findParent(parent,u);
    v=findParent(parent,v);
    if(rank[u]<rank[v])
        parent[u]=v;
    else if(rank[v]<rank[u])
        parent[v]=u;
    else{
        parent[v]=u;
        rank[u]++;
        }
}

int minimumSpanningTree(vector<vector<int>>&edges,int n){
    sort(edges.begin(),edges.end(),comp);
    vector<int>parent(n+1);
    vector<int>rank(n+1);
    int minweight=0;
    makeSet(parent,rank,n);
    for(int i=0;i<edges.size();i++){
        int u=findParent(parent,edges[i][0]);
        int v=findParent(parent,edges[i][1]);
        int wt=edges[i][2];
       if(u!=v){
        minweight+=wt;
        unionSet(u,v,parent,rank);
       }
    }
    return minweight;
}


int main(){
    // ----->MINIMUM SPANNING TREE USING KRUSKAL'S ALGORITHM<-----
    vector<vector<int>>edges={{5,4,9},{5,1,4},{4,1,1},{1,2,2},{4,2,3},{4,3,5},{3,2,3},{3,6,8},{2,6,7}};
    cout<<"Minimum weight "<<minimumSpanningTree(edges,6)<<endl;
    
    return 0;
}