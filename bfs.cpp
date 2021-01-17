//code for bfs on graphs//
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
vector <ll> dfs(map<ll,vector<ll>>&g,ll N){
    vector<ll> ans;
    bool visited[N+1]={false};
    queue<ll> q;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        ll x=q.front();
        ans.pb(x);
        q.pop();
        for(int i:g[x]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    return ans;
}
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n,e;
        cin>>n>>e;
        //vector<ll> g[n];
        map<ll,vector<ll>> g;
        for(ll i=0;i<e;i++){
            ll u,v;
            cin>>u>>v;
            g[u].pb(v);
            //g[v].pb(u);
        }
        vector<ll> ans=dfs(g,n);
        for(ll i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
