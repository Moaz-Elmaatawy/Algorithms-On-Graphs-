#include<bits/stdc++.h>
using namespace std;
void BFS(int u,int v,vector<vector<int>>&adj,vector<int>&dist,vector<bool>&visited){
    dist[u]=0;
    visited[u]=1;
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int i=0;i<adj[curr].size();++i){
            if(!visited[adj[curr][i]]){
                q.push(adj[curr][i]);
                visited[adj[curr][i]]=1;
                dist[adj[curr][i]]=1+dist[curr];
            }
        }
    }
    cout<<dist[v]<<endl;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<int>dist(n,-1);
    vector<bool>visited(n,0);
    vector<vector<int>>adj(n,vector<int>());
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    int u,v;
    cin>>u>>v;
    BFS(u-1,v-1,adj,dist,visited);
    return 0;
}
