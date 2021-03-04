#include "bits/stdc++.h"
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define mem0(a) memset(a,0,sizeof(a))
#define mod 100000007
#define NM 10000000
bool isPrime(ll N){ for(ll i=2;i*i<=N;++i){if(N%i==0) return false;}return true;}
using namespace std;
int lps(string s,string t){
     int n=s.size();
    int m=t.size();
    vector<vector<ll>> dp(m+1,vector<ll>(n+1,0));
    //dp[0][0]=1;
    for(ll i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(ll j=0;j<=n;j++){
        dp[0][j]=1;
    }


    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            if(t[i-1]==s[j-1]){
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1];

            }
            else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }
   
    return dp[m][n];
        
        
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("dh1.txt","r",stdin);
    freopen ("dh3.txt","w",stdout);
    #endif
    string s1,s2;
    cin>>s1;
    cin>>s2;

    cout<<lps(s1,s2)<<endl;
   // cout<<ans<<endl;


}
