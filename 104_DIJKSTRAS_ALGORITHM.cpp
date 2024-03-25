#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>>&vec,int vertices,int edges,int source){
    //create adjcency list
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back(make_pair(v,w));
        // adj[v].push_back(make_pair(u,w));
    }
    vector<int>dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
    // creation of set on the basis (distance,node)
    set<pair<int,int>>st;
    dist[source]=0;
    st.insert(make_pair(0,source));
    while(!st.empty()){
        //fetch top record
        auto top=*(st.begin());
        int nodeDistance=top.first;
        int topNode=top.second;
        //remove top record now
        st.erase(st.begin());

        //traverse on neighbours
        for(auto neighbour:adj[topNode]){
            if(nodeDistance+neighbour.second<dist[neighbour.first]){
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
                //if record found then erase it
                if(record!=st.end()){
                    st.erase(record);
                }
                //distance update
                dist[neighbour.first]=nodeDistance+neighbour.second;
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    return dist;
}

int main(){
    // ----->DIJKSTRA'S ALGORITHM FOR SHORTEST PATH<-----
    // vector<vector<int>>edges={{0,2,1},{2,1,3},{0,1,7},{1,3,5},{3,4,7},{1,4,1},{0,3,2}};
    vector<vector<int>>edges={{0,1,5},{0,2,10},{2,1,-8}};
    int src=0;
    // vector<int>dist=dijkstra(edges,5,7,src);
    vector<int>dist=dijkstra(edges,3,3,src);
    cout<<"Shortest distance of all node from "<<src<<" -> "<<dist[1];
    // for(auto i:dist)
    // cout<<i<<" ";
    // cout<<endl;
    
    return 0;
}