#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
bool graph_sorting(ll i,vector<ll> &ans,vector<ll> &vis,priority_queue<ll> g[]){
    vis[i]=1;
    while(!g[i].empty()){
        ll nbr=g[i].top();
        g[i].pop();
        if(!vis[nbr]){
            bool t=graph_sorting(nbr,ans,vis,g);
                if(!t){
                    return false;
                }
            }
            else if(vis[nbr]==1){
                return false;
            }
        }
    vis[i]=2;
    ans.push_back(i);
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("a1.txt","r",stdin);
    freopen ("a2.txt","w",stdout);
    #endif
    ll n,m;
    cin>>n>>m;
    priority_queue<ll> g[n+1];
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push(y);
    }
    vector<ll> ans;
    vector<ll> vis(n+1,0);
    bool flag=true;
    for(ll i=n;i>=1;i--){
        if(!vis[i]){
            flag=graph_sorting(i,ans,vis,g);
            if(flag==false){
                cout<<"Sandro fails."<<endl;
                ans={};
                break;
            }
            
            else{
                continue;
            }
            
        }
    }
    reverse(ans.begin(),ans.end());
    //cout<<1<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

}
