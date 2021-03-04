#include "bits/stdc++.h"
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define mem0(a) memset(a,0,sizeof(a))
#define mod 100000007
#define NM 10000000
bool isPrime(ll N){ for(ll i=2;i*i<=N;++i){if(N%i==0) return false;}return true;}
using namespace std;
string lps(string s){
    int n=s.size();
    string s1;
    s1=s;
    reverse(s.begin(),s.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    int ans=-1;
    string a="";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==s1[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>ans){
                    string temp=s.substr(i-dp[i][j],dp[i][j]);
                    string rtemp=temp;
                    reverse(rtemp.begin(),rtemp.end());
                    if(temp==rtemp){
                        ans=dp[i][j];
                        a=temp;
                    }
                }

            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return a;
        
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("dh1.txt","r",stdin);
    freopen ("dh3.txt","w",stdout);
    #endif
    string s1;
    cin>>s1;
    string ans=lps(s1);
    cout<<ans<<endl;


}
