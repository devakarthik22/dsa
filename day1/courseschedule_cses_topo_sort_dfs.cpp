#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pi pair<ll,ll>
using namespace std;
bool topo_sort(vector<ll> g[],ll x,vector<ll> &vis,vector<ll> &ans){
    vis[x]=1;
    for(auto nbr:g[x]){
        if(!vis[nbr]){
            bool a=topo_sort(g,nbr,vis,ans);
            if(!a){
                return false;

            }
        }
        else if(vis[nbr]==1){
            return false;
        }
    }
    vis[x]=2;
    ans.pb(x);
    return true;

}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("a1.txt","r",stdin);
    freopen ("a2.txt","w",stdout);
    #endif
    ll n,m;
    cin>>n>>m;
    vector<ll> g[n+1];
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        g[a].pb(b);
    }
    vector<ll> ans;
    vector<ll> vis(n+1);
    bool flag=true;
    for(ll i=1;i<=n;i++){
        if(vis[i]!=2){
            bool a=topo_sort(g,i,vis,ans);
            if(!a){
                flag=false;
                ans={};
                break;
            }
        }

    }
    if(flag==false){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        //cout<<ans.size()<<endl;
        reverse(ans.begin(),ans.end());
        for(ll i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
   



}
