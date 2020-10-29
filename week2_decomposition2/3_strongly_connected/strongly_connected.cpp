#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int clock0 = 1;

int post(vector<int> &postv,int x){
    postv[x]=clock0;
    ++clock0;
    return clock0;
}

int pre(vector<int> &prev,int x){
    prev[x]=clock0;
    ++clock0;
    return clock0;
}

int explore(vector<vector<int> > &adj ,vector<int> &v,vector<int> &prev,vector<int> &postv,int x){
    v[x]=1;
    pre(prev,x);
    for(int i=0;i<adj[x].size();++i){
        if(v[adj[x][i]]==0){
            explore(adj,v,prev,postv,adj[x][i]);
        }
    }
    post(postv,x);
}

int dfs(vector<vector<int> > &adj ,vector<int> &v ,vector<int> &prev,vector<int> &postv){
    for(int i=0;i<v.size();++i){
        if(v[i]==0){
            explore(adj,v,prev,postv,i);
        }
    }
}

int number_of_strongly_connected_components(vector<vector<int> > adj ,vector<vector<int> > adj_r,vector<int> &v ,vector<int> &prev,vector<int> &postv) {
  int result = 0;
  dfs(adj_r,v,prev,postv);
  max_element(postv.begin(),postv.end())-postv.begin();
  vector<int>v2(v.size());
  vector<int>postv2(v.size());
  postv2.swap(postv);
  for(int i=0;i<v.size();++i){
    int index=max_element(postv2.begin(),postv2.end())-postv2.begin();
    postv2[index]=0;
    if(v2[index]==0){
        explore(adj,v2,prev,postv,index);
        ++result;
    }
  }
/*
  for(int i=0;i<prev.size();++i){
    cout<<prev[i]<<",";
  }
  cout<<endl<<endl;
  for(int i=0;i<prev.size();++i){
    cout<<postv[i]<<",";
  }
  cout<<endl<<endl;*/
  return result;
}

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > adj_r(n, vector<int>());
  vector<int>v(n);
  vector<int>prev(n);
  vector<int>postv(n);
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj_r[y - 1].push_back(x - 1);
  }
  cout << number_of_strongly_connected_components(adj,adj_r,v,prev,postv);
}
