#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void dfs(vector<vector<int> > &adj, vector<int> &v, vector<int> &order, int x) {
    v[x]=1;
    for(int i=0;i<adj[x].size();++i){
        if(v[adj[x][i]]==0){
            dfs(adj,v,order,adj[x][i]);
        }
    }
    order.push_back(x);
}

vector<int> toposort(vector<vector<int> > adj) {
    vector<int> v(adj.size(), 0);
    vector<int> order;

    for(int i=0;i<v.size();++i){
        if(v[i]==0){
            dfs(adj,v,order,i);
        }
    }
    return order;
}

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  reverse(order.begin(),order.end());
  for (size_t i = 0; i < order.size(); i++) {
    cout << order[i] + 1 << " ";
  }
}
