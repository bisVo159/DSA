,unordered_map<int,list<int>>&adj){
    visited[node]=true;
    dfsVisited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){