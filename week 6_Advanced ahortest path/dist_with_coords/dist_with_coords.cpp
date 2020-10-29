/***
Bidirectional A* algorithm :54.21sec---->74309632byte
***/
#include <bits/stdc++.h>
#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <cmath>

using namespace std;
typedef vector<vector<vector<int>>>Adj;
typedef long long ll;
typedef vector<priority_queue<pair<double, int>,vector<pair<double,int>>,greater<pair<double,int>>>> Queue;

const ll inf = numeric_limits<ll>::max() / 4;

class AStar {
    int n;
    Adj adj;
    Adj w;
    vector<vector<ll>>dist;
    vector<int> workset_;
    vector<int>visited_1;
    vector<int>visited_2;
    vector<pair<int,int>>xy;

public:
    AStar(int n_, Adj ADJ, Adj cost, vector<pair<int,int>> x_y)
        : n(n_), adj(ADJ), w(cost), dist(2,vector<ll>(n,inf)), visited_1(n), visited_2(n), xy(x_y)
    { workset_.reserve(n); }

    void clear(){
        for (int i = 0; i < workset_.size(); ++i) {
            int v = workset_[i];
            dist[0][v] = dist[1][v] = inf;
            visited_1[v] = 0;
            visited_2[v] = 0;
        }
        workset_.clear();
    }
    double to(int s,int t){
        return sqrt(pow(xy[s].first-xy[t].first,2)+pow(xy[s].second-xy[t].second,2));
    }
    ll query(int s, int t) {
        clear();
        Queue p(2);
        dist[0][s]=0;
        dist[1][t]=0;
        workset_.push_back(s);
        workset_.push_back(t);
        p[0].push(make_pair(0,s));
        p[1].push(make_pair(0,t));
        while(!p[0].empty()&&!p[1].empty()){
            int u=p[0].top().second;
            p[0].pop();
            for(int i=0;i<adj[0][u].size();++i){
                if(dist[0][adj[0][u][i]] > dist[0][u]+w[0][u][i]){
                    dist[0][adj[0][u][i]]=dist[0][u]+w[0][u][i];
                    double h=dist[0][u]+w[0][u][i]+(to(adj[0][u][i],t)+to(adj[0][u][i],s))/2;
                    p[0].push(make_pair(h,adj[0][u][i]));
                    workset_.push_back(adj[0][u][i]);
                }
            }
            if(visited_2[u]) break;
            visited_1[u]=1;

            int v=p[1].top().second;
            p[1].pop();
            for(int i=0;i<adj[1][v].size();++i){
                if(dist[1][adj[1][v][i]] >dist[1][v]+w[1][v][i]){
                    dist[1][adj[1][v][i]]=dist[1][v]+w[1][v][i];
                    double h=dist[1][v]+w[1][v][i]-(to(adj[1][v][i],t)+to(adj[1][v][i],s))/2;
                    p[1].push(make_pair(h,adj[1][v][i]));
                    workset_.push_back(adj[1][v][i]);
                }
            }
            if(visited_1[v])break;
            visited_2[v]=1;
        }
        ll ans=inf;
        for(int i=0;i<n;++i)
            ans=min(ans,dist[0][i]+dist[1][i]);
        return ans==inf?-1:ans;
    }
};

int main() {
    freopen("3.txt","r",stdin);
    freopen("3.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    int n, m;//cin>>n>>m;
    scanf("%d%d", &n, &m);
    vector<pair<int,int>> xy(n);
    for (int i=0;i<n;++i){
        int a,b;
        scanf("%d%d", &a, &b);
        xy[i] = make_pair(a,b);
    }
    Adj adj(2, vector<vector<int>>(n));
    Adj cost(2, vector<vector<int>>(n));
    for (int i=0; i<m; ++i) {
        int u, v, c;//cin>>u>>v>>c;
        scanf("%d%d%d", &u, &v, &c);
        adj[0][u-1].push_back(v-1);
        cost[0][u-1].push_back(c);
        adj[1][v-1].push_back(u-1);
        cost[1][v-1].push_back(c);
    }

    AStar astar(n, adj, cost, xy);

    int t;//cin>>t;
    scanf("%d", &t);
    for (int i=0; i<t; ++i) {
        int u, v;//cin>>u>>v;
        scanf("%d%d", &u, &v);
        printf("%lld\n", astar.query(u-1, v-1));
        //cout<<astar.query(u-1, v-1)<<endl;
    }
}
