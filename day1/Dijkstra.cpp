#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
using namespace std;
ll dis[100];
ll state[100];
vector<pair<ll,ll>> v[10];
void djs(ll x){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    pair<ll,ll> p;
    dis[x]=0;
    q.push(mp(dis[x],x));
    while(!q.empty()){
        p=q.top();
        q.pop();
        ll curr=p.second;
        if(state[curr]==1){
            continue;
        }
        state[curr]=1;
        for(ll i=0;i<v[curr].size();i++){
            if(state[v[curr][i].first]==0){
                if(dis[curr]+v[curr][i].second<dis[v[curr][i].first]){
                    dis[v[curr][i].first]=dis[curr]+v[curr][i].second;
                    p=make_pair(dis[v[curr][i].first],v[curr][i].first);
                    q.push(p);

                }
            }
        }
    }

}

int main() {
    int n,m,x,y,wt;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        cin>>x>>y>>wt;
        v[x].push_back(make_pair(y,wt));
        v[y].push_back(make_pair(x,wt));
    }
    memset(state,0,sizeof(state));
    for(ll i=1;i<=n;i++){
        dis[i]=INT_MAX;
    }
    djs(1);
    for(ll i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;


    
}
