#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void bellman_ford(int start,vector<vector<int>>&adj,vector<vector<int>>&w,int n,int m ){
    long long inf=10000000000;
    vector<int>prev(n,-1);
    vector<ll>dist(n,inf);
    dist[start]=0;
    for(int k=0;k<n-1;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<adj[i].size();++j){
                if(dist[i]!=inf&& dist[adj[i][j]]>dist[i]+w[i][adj[i][j]]){
                    prev[adj[i][j]]=i;
                    dist[adj[i][j]]=dist[i]+w[i][adj[i][j]];
                }
            }
        }
    }
    queue<int>q;
    for(int i=0;i<n;++i){
        for(int j=0;j<adj[i].size();++j){
            if(dist[i]!=inf&&dist[adj[i][j]]>dist[i]+(ll)w[i][adj[i][j]]){
                q.push(adj[i][j]);
                dist[adj[i][j]]=-1;
            }
        }
    }
    while(!q.empty()){
        int s=q.front();
        q.pop();
        dist[s]=-1;
        for(int i=0;i<adj[s].size();++i){
                if(dist[adj[s][i]]!=-1)
                    q.push(adj[s][i]);
        }
    }
    for(int i=0;i<n;++i){
        if(dist[i]==inf)
            cout<<"*"<<endl;
        else if(dist[i]==-1)
            cout<<"-"<<endl;
        else
            cout<<dist[i]<<endl;
    }

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
    int s;cin>>s;
    bellman_ford(s-1,adj,w,n,m);
    return 0;
}
