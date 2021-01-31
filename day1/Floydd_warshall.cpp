#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pi pair<ll,ll>
#define me 1000000000000
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("a1.txt","r",stdin);
    freopen ("a2.txt","w",stdout);
    #endif
    ll n,m,q;
    cin>>n>>m>>q;
    ll dp[n+1][n+1];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
           
                dp[i][j]=me;
            
        }
    }
    for(ll i=0;i<m;i++){
        ll a,b,wt;
        cin>>a>>b>>wt;
	dp[a][a]=0;
	dp[b][b]=0;
        dp[a][b]=min(dp[a][b],wt);
        dp[b][a]=min(dp[a][b],wt);
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
               
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }

    }
    //cout<<dp[1][4]<<endl;
    for(ll i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        if(dp[a][b]==me){
            cout<<-1<<endl;
        }
        else{
            cout<<dp[a][b]<<endl;
        }
    }

    
 
}
