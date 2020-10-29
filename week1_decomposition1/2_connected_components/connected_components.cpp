#include <iostream>
#include <vector>
using namespace std;

void explor(int x,vector<vector<int> > &adj ,vector<bool> &v ,vector<int >&cc,int c){
    v[x]=1;
    cc[x]=c;
    for(int i=0;i<adj[x].size();++i){
        if(v[adj[x][i]]==0){
            explor(adj[x][i],adj,v,cc,c);
        }

    }
}

int number_of_components(vector<vector<int> > &adj ,vector<bool> &v,int n,vector<int>&cc) {
  int res = 0;
  for(int i=0;i<n;++i){
    if (v[i]==0){
        explor(i,adj,v,cc,res);
        ++res;
    }
  }

  return res;
}

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<bool>v(n);
  vector<int>cc(n);
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  cout << number_of_components(adj,v,n,cc)<<endl;

  for(int i=0;i<n;++i){
    cout<<cc[i]<<",";
  }
}
