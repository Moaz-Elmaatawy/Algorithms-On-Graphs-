#include<bits/stdc++.h>
using namespace std;
class disjoint_set{
vector<int>parent;
vector<int>rank;
public:
    disjoint_set(int n){
        parent.resize(n);
        rank.resize(n);
    }
    void make_set(int i){
        parent[i]=i;
        rank[i]=0;
    }
    int  find(int i){
        if(parent[i]!=i)
            parent[i]=find(parent[i]);
        return parent[i];
    }
    void Union(int i,int j){
        int r_i=find(i);
        int r_j=find(j);
        if(r_i==r_j)return ;
        if(r_i>r_j)
            parent[r_j]=r_i;
        else{
            parent[r_i]=r_j;
            if(rank[r_i]==rank[r_j])
                ++rank[r_j];
        }
    }
};
int main() {
    int n;cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;++i)
        cin>>v[i].first>>v[i].second;
    int k;cin>>k;
    vector<pair<double,pair<int,int>>>E;
    for(int i=0;i<n-1;++i)
        for(int j=1+i;j<n;++j)
            E.push_back(make_pair(sqrt(pow(v[i].first-v[j].first,2)+pow(v[i].second-v[j].second,2)),make_pair(i,j)));

    sort(E.begin(),E.end());
    disjoint_set D(n);
    for(int i=0;i<n;++i)
        D.make_set(i);
    int counter=n;
    int ans=0;
    while(counter!=k-1){
        if(D.find(E[ans].second.first)!=D.find(E[ans].second.second)){
            --counter;
            D.Union(E[ans].second.first,E[ans].second.second);
        }
        ++ans;
    }
    cout<<setprecision(10)<<E[ans-1].first<<endl;
    return 0;
}

