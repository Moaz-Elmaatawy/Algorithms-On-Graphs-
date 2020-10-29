#include<bits/stdc++.h>
using namespace std;
bool bellman_ford(vector<vector<int>>&adj,vector<vector<int>>&w,int n,int m ){
    vector<int>prev(n,-1);
    vector<int>dist(n,10000);
    dist[0]=0;
    for(int k=0;k<n-1;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<adj[i].size();++j){
                if(dist[adj[i][j]]>dist[i]+w[i][adj[i][j]]){
                    prev[adj[i][j]]=i;
                    dist[adj[i][j]]=dist[i]+w[i][adj[i][j]];
                }
            }
        }
    }
    for(int i=0;i<n;++i){
            for(int j=0;j<adj[i].size();++j){
                if(dist[adj[i][j]]>dist[i]+w[i][adj[i][j]]){
                    return 1;
                }
            }
        }
    return 0;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>());
    vector<vector<int>>w(n,vector<int>(n));

    for(int i=0;i<m;++i){
        int u,v,W;
        cin>>u>>v>>W;
        adj[u-1].push_back(v-1);
        w[u-1][v-1]=W;
    }
    cout<<bellman_ford(adj,w,n,m)<<"\n";
    return 0;
}
