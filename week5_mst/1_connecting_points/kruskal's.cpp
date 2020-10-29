#include<bits/stdc++.h>
using namespace std;

class disjoint{
    vector<int>Rank;
    vector<int>Parent;
public:
    disjoint(int n){
        Rank.resize(n);
        Parent.resize(n);
    }
    void make_set(int i){
        Parent[i]=i;
        Rank[i]=0;
    }

    int Find(int i){
        if(i!=Parent[i])
            Parent[i]=Find(Parent[i]);
        return Parent[i];
    }

    void Union(int a,int b){
        int ra=Find(a);
        int rb=Find(b);
        if(ra==rb)return;
        if(Rank[ra]>Rank[rb])
            Parent[rb]=ra;
        else{
            Parent[ra]=rb;
            if(Rank[ra]==Rank[rb])
                ++Rank[rb];
        }
    }
};
int main() {
    int n;cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;++i){
        cin>>v[i].first>>v[i].second;
    }
    vector<pair<double ,pair<int,int>>>E;
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            double a=sqrt(pow((v[i].first-v[j].first),2)+pow((v[i].second-v[j].second),2));
            E.push_back(make_pair(a,make_pair(i,j)));
        }
    }
    sort(E.begin(),E.end());
    double ans=0;
    disjoint D(n);
    for(int i=0;i<n;++i)
        D.make_set(i);
    int counter=0;
    for(int i=0;i<E.size();++i){
        if(D.Find(E[i].second.first)!=D.Find(E[i].second.second)){
            ++counter;
            D.Union(E[i].second.first,E[i].second.second);
            ans+=E[i].first;
            if(counter==n-1)break;
        }
    }

    cout<<setprecision(10)<<ans<<endl;
    return 0;
}

