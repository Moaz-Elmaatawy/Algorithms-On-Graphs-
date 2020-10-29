#include<bits/stdc++.h>
using namespace std;
int ord=0;
void DFS(int s,vector<vector<int>>&adj,vector<int>&visited,vector<int>&post){
    visited[s]=1;
    ++ord;
    for(int i=0;i<adj[s].size();++i){
        if(!visited[adj[s][i]])
            DFS(adj[s][i],adj,visited,post);
    }
    ++ord;
    post[s]=ord;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>());
    vector<vector<int>>adj_rev(n,vector<int>());
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj_rev[v-1].push_back(u-1);
    }
    vector<int>post(n);
    vector<int>post2(n);
    vector<int>visited(n);
    for(int i=0;i<n;++i){
        if(!visited[i])
            DFS(i,adj_rev,visited,post);
    }

    fill(visited.begin(),visited.end(),0);
    ord=0;
    int ans=0;
    for(int i=0;i<n;++i){
        int s=max_element(post.begin(),post.end())-post.begin();
        if(!visited[s]){
            ++ans;
            DFS(s,adj,visited,post2);
            post[s]=-1;
        }else post[s]=-1;
    }

    cout<<ans<<endl;
    return 0;
}
