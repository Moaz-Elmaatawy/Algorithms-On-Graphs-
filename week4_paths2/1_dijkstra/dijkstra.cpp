#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

int distance(vector<vector<int> > &adj, vector<vector<int> > &w, int s, int t ,vector<int> &dis ,vector<int> &prev) {
    dis[s]=0;
    vector<int>h(dis.size(),10000);
    h[s]=0;
    int max0=*max_element(h.begin(),h.end());
    for(int i=0;i<dis.size();++i){
        int u=min_element(h.begin(),h.end())-h.begin() ;
        h[u]=10000;
        for(int i=0;i<adj[u].size();++i){
            if(dis[adj[u][i]]>dis[u]+w[u][adj[u][i]]){
                dis[adj[u][i]]=dis[u]+w[u][adj[u][i]];
                prev[adj[u][i]]=u;
                h[adj[u][i]]=dis[adj[u][i]];
            }
        }
   }
  // cout<<dis[t]<<endl;
    if(dis[t]==10000)
        return -1;
    else
        return dis[t];
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>(n));
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1][y-1]=w;
  }
  int s, t;
  cin >> s >> t;
  s--, t--;

  vector<int> dis(n,10000);
  vector<int> prev(n,-1);

  cout << distance(adj, cost, s, t ,dis ,prev);
}
