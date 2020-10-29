#include <iostream>
#include <vector>
using namespace std;
int check =0;
int explore(vector<vector<int> > &adj , vector<int> &v ,int x ){
    if(v[x]==1){
        check =1;
        return check;
    }
    v[x]=1;
    for(int i=0;i<adj[x].size();++i){
        if(v[adj[x][i]]==0||v[adj[x][i]]==1){
            explore(adj,v,adj[x][i]);
        }
    }
    v[x]=2;
    return check;
}

int acyclic(vector<vector<int> > &adj , vector<int> &v ) {
    for(int i=0;i<v.size();++i){
        if(v[i]==0){
            explore(adj,v,i);
        }
    }

  return check;
}

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<int>v(n);
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  cout << acyclic(adj,v );
//  for(int i=0;i<n;++i){
//    cout<<v[i]<<",";
//  }
}
