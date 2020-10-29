#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>());
    vector<int>visited(n);
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    queue<int>q;
    q.push(0);
    visited[0]=1;
    int flag=0;
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(int i=0;i<adj[s].size();++i){
            if(!visited[adj[s][i]]){
                q.push(adj[s][i]);
                visited[s]==1?visited[adj[s][i]]=2:visited[adj[s][i]]=1;
            }
            else if(visited[s]!=0&&visited[s]==visited[adj[s][i]]){
                flag=1;
            }
        }
    }

    if(flag)cout<<0<<endl;
    else cout<<1<<endl;
    return 0;
}
