#include <iostream>
#include <vector>
using namespace std;



int reach(vector<vector<int> > &adj, int x, int y , vector<bool> &v) {

  v[x]=1;
  //cout<<v[adj[x][0]]<<","<<adj[x].size()<<","<<adj[x][0]<<endl;
  for(int i=0;i<adj[x].size();++i){
    if(v[adj[x][i]]==0){
        reach(adj,adj[x][i],y,v);
    }
  }

  return v[y];
}

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<bool>v(n);
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  cin >> x >> y;

  //cout<<adj[2].size()<<endl;
  cout << reach(adj, x - 1, y - 1 ,v);
}
