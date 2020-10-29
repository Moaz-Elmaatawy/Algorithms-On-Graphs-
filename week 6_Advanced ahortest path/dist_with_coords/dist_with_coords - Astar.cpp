/***
A* time:19.63 sec
memory :74362880
***/
#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <cmath>

using namespace std;
typedef vector<vector<int>>Adj;
typedef long long ll;
typedef priority_queue<pair<double, int>,vector<pair<double,int>>,greater<pair<double,int>>> Queue;

const ll inf = numeric_limits<ll>::max() / 4;

class AStar {
    int n;
    Adj adj;
    Adj w;
    vector<ll> dist;
    vector<int> workset_;
    vector<bool> visited;
    vector<pair<int,int>>xy;

public:
    AStar(int n_, Adj ADJ, Adj cost, vector<pair<int,int>> x_y)
        : n(n_), adj(ADJ), w(cost), dist(n,inf), visited(n), xy(x_y)
    { workset_.reserve(n); }

    void clear(){
        for (int i = 0; i <workset_.size(); ++i)
            dist[workset_[i]] = inf;
        workset_.clear();
    }
    double to(int s,int t){
        return sqrt(pow(xy[s].first-xy[t].first,2)+pow(xy[s].second-xy[t].second,2));
    }
    ll query(int s, int t) {
        clear();
        Queue p;
        dist[s]=0;
        workset_.push_back(s);
        p.push(make_pair(0,s));
        while(!p.empty()){
            int u=p.top().second; if(u == t)break;
            p.pop();
            for(int i=0;i<adj[u].size();++i){
                if(dist[adj[u][i]] > dist[u]+w[u][i]){
                    dist[adj[u][i]]=dist[u]+w[u][i];
                    double h=dist[u]+w[u][i]+to(adj[u][i],t);
                    p.push(make_pair(h,adj[u][i]));
                    workset_.push_back(adj[u][i]);
                }
            }
        }
        return dist[t]==inf?-1:dist[t];
    }
};

int main() {
//    freopen("3.txt","r",stdin);
  //  freopen("3.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pair<int,int>> xy(n);
    for (int i=0;i<n;++i){
        int a,b;
        scanf("%d%d", &a, &b);
        xy[i] = make_pair(a,b);
    }
    Adj adj(n);
    Adj cost(n);
    for (int i=0; i<m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u-1].push_back(v-1);
        cost[u-1].push_back(c);
    }

    AStar astar(n, adj, cost, xy);

    int t;
    scanf("%d", &t);
    for (int i=0; i<t; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%lld\n", astar.query(u-1, v-1));
    }
}
