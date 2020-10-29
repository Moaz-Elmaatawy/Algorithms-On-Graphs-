#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf =INT_MAX;
int bi_dijkstra(int n,int s,int t,vector<vector<vector<int>>>&adj,vector<vector<vector<int>>>&w,vector<vector<ll>>&dist,vector<int>&visited){
        vector<priority_queue<pair<int ,int>,vector<pair<int ,int>>,greater<pair<int ,int>>>>p(2);
        fill(dist[0].begin(),dist[0].end(),inf);
        fill(dist[1].begin(),dist[1].end(),inf);
        fill(visited.begin(),visited.end(),0);

        dist[0][s]=0;dist[1][t]=0;
        p[0].push(make_pair(0,s));
        p[1].push(make_pair(0,t));

        while(!p[0].empty()||!p[0].empty()){
            int u=p[0].top().second;
            p[0].pop();
            for(int i=0;i<adj[0][u].size();++i){
                if(dist[0][adj[0][u][i]]>dist[0][u]+w[0][u][i]){
                    dist[0][adj[0][u][i]]=dist[0][u]+w[0][u][i];
                    p[0].push(make_pair(dist[0][adj[0][u][i]],adj[0][u][i]));
                }
            }
            if(visited[u]==2)break;
            visited[u]=1;

            int v=p[1].top().second;
            p[1].pop();
            for(int i=0;i<adj[1][v].size();++i){
                if(dist[1][adj[1][v][i]]>dist[1][v]+w[1][v][i]){
                    dist[1][adj[1][v][i]]=dist[1][v]+w[1][v][i];
                    p[1].push(make_pair(dist[1][adj[1][v][i]],adj[1][v][i]));
                }
            }
            if(visited[v]==1)break;
            visited[v]=2;
        }
        ll ans=INT_MAX;
        for(int i=0;i<n;++i){
            ans=min(ans,dist[0][i]+dist[1][i]);
        }
        ans=ans==INT_MAX?-1:ans;
        return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<vector<vector<int>>>adj(2,vector<vector<int>>(n));
    vector<vector<vector<int>>>w(2,vector<vector<int>>(n));
    vector<vector<ll>>dist(2,vector<ll>(n,inf));

    vector<int>visited(n,0);

    for(int i=0;i<m;++i){
        int a,b,c;cin>>a>>b>>c;
        adj[0][a-1].push_back(b-1);
        adj[1][b-1].push_back(a-1);
        w[0][a-1].push_back(c);
        w[1][b-1].push_back(c);
    }
    int q;cin>>q;
    for(int ii=0;ii<q;++ii){
        int s,t;cin>>s>>t;
        cout<<bi_dijkstra(n,s-1,t-1,adj,w,dist,visited)<<endl;

    }

    return 0;
}
