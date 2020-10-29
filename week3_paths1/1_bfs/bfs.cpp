#include <iostream>
#include <vector>
#include <queue>

using  namespace std;

int distance(vector<vector<int> > &adj, int s, int t , vector<int> &v) {
  queue<int>q;
  v[s]=0;
  q.push(s);
  while(q.empty()==0){
    s=q.front();
    for(int i=0;i<adj[s].size();++i){
        if(v[adj[s][i]]==-1){
            v[adj[s][i]]=v[s]+1;
            q.push(adj[s][i]);
        }
    }
    q.pop();
  }
  return v[t];
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  cin >> s >> t;
  s--, t--;
  vector<int>dis(n,-1);
  cout << distance(adj, s, t ,dis);
}
