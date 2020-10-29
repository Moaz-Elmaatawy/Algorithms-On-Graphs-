#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

double W(int x1,int y1,int x2,int y2){
double w=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
return w;
}

double minimum_distance(vector<int> x, vector<int> y) {
    int n= x.size();
    double result = 0.;
    vector<vector<int> >adj(n,vector<int>());
    vector<vector<double> > cost(n, vector<double>());
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i!=j){
                adj[i].push_back(j);
                cost[i].push_back(W(x[i],y[i],x[j],y[j]));
            }
        }
    }

    vector<double>v(n,100000);
    vector<double>dis(n,100000);
    vector<int>prev(n,-1);
    v[0]=0;
    dis[0]=0;
    for(int i=0;i<n;++i){
        int u=min_element(v.begin(),v.end())-v.begin();
        result+=v[u];
        v[u]=1000007;
        for(int i=0;i<adj[u].size();++i){
            if(v[adj[u][i]]!=1000007&&v[adj[u][i]]>cost[u][i]){
                v[adj[u][i]]=cost[u][i];
            }
        }

    }


    return result;
}

int main() {
  size_t n;
  cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  cout << setprecision(10) << minimum_distance(x, y) << endl;
}
