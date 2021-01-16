#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
void dfs_helper(vector<ll> g[],vector<ll> &ans,bool visited[],ll src){
    ll x=src;
    visited[x]=true;
    ans.push_back(x);
    for(auto i:g[x]){
        if(!visited[i]){
            dfs_helper(g,ans,visited,i);
        }
    }
}
vector <ll> dfs(vector<ll> g[],ll N){
    vector<ll> ans;
    bool visited[N+1]={false};
    dfs_helper(g,ans,visited,0);
    return ans;
}
int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("a1.txt","r",stdin);
    //freopen ("a2.txt","w",stdout);
    //#endif
    ll t;
    cin>>t;
    while(t--){
        ll n,e;
        cin>>n>>e;
        vector<ll> g[n];
        for(ll i=0;i<e;i++){
            ll u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        vector<ll> ans=dfs(g,n);
        for(ll i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
