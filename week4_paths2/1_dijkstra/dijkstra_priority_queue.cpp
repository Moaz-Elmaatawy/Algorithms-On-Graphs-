#include<bits/stdc++.h>
using namespace std;
int Dijkstra(vector<vector<int>>&adj,vector<vector<int>>&w,int u,int v ){
    int n=adj.size();
    vector<int>prev(n,-1);
    vector<int>dist(n,10000);
    priority_queue<pair<int ,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    dist[u]=0;p.push(make_pair(0,u));
    while(!p.empty()){
        int s=(p.top()).second;
        p.pop();
        for(int i=0;i<adj[s].size();++i){
            if(dist[adj[s][i]]>dist[s]+w[s][adj[s][i]]){
                dist[adj[s][i]]=dist[s]+w[s][adj[s][i]];
                prev[adj[s][i]]=s;
                p.push(make_pair(dist[adj[s][i]],adj[s][i]));
            }
        }
    }
    return dist[v]==10000?-1:dist[v];
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>());
    vector<vector<int>>w(n,vector<int>(n));
    for(int i=0;i<m;++i){
        int u,v,x;
        cin>>u>>v>>x;
        adj[u-1].push_back(v-1);
        w[u-1][v-1]=x;
    }
    int u,v;cin>>u>>v;
    cout<<Dijkstra(adj,w,u-1,v-1)<<endl;
    return 0;
}
