#include "bits/stdc++.h"
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define mem0(a) memset(a,0,sizeof(a))
#define mod 100000007
#define NM 10000000
bool isPrime(ll N){ for(ll i=2;i*i<=N;++i){if(N%i==0) return false;}return true;}
using namespace std;
 bool isSubsequence(string s, string t) {
        int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    dp[0][0]=1;
    for(ll i=1;i<=n;i++){
        dp[i][0]=0;
    }
    for(ll j=1;j<=m;j++){
        dp[0][j]=1;
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1];

            }
            else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }
   
    return dp[n][m];
        
    }
int main() {
    #ifndef ONLINE_JUDGE
    freopen("dh1.txt","r",stdin);
    freopen ("dh3.txt","w",stdout);
    #endif
    string s1,s2;
    cin>>s1;
    cin>>s2;

    cout<<isSubsequence(s2,s1)<<endl;
   // cout<<ans<<endl;


}
