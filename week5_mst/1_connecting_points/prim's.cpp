#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//prim's algorithm for MST
int main() {
    int n;cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;++i){
        cin>>v[i].first>>v[i].second;
    }
    vector<vector<int>>adj(n,vector<int>());
    vector<vector<double>>w(n,vector<double>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i!=j)adj[i].push_back(j);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i!=j){w[i][j]=sqrt(pow((v[i].first-v[j].first),2)+pow((v[i].second-v[j].second),2));}
        }
    }
    vector<double>dist(n,100000);
    vector<bool>visited(n,0);
    vector<int>prev(n,-1);
    dist[0]=0;
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>p;
    p.push(make_pair(0,0));
    double ans=0;
    while(!p.empty()){
        int s=p.top().second;
        if(!visited[s])ans+=p.top().first;
        p.pop();
        visited[s]=1;
        for(int i=0;i<adj[s].size();++i){
            if(!visited[adj[s][i]]&&w[s][adj[s][i]]<dist[adj[s][i]]){
                dist[adj[s][i]]=w[s][adj[s][i]];
                p.push(make_pair(dist[adj[s][i]],adj[s][i]));
                prev[adj[s][i]]=s;
            }
        }
    }
    cout<<setprecision(10)<<ans<<endl;
    return 0;
}

