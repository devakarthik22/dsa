//code n explore
#include "bits/stdc++.h"
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define mem0(a) memset(a,0,sizeof(a))
#define mod 100000007
#define NM 10000000
bool isPrime(ll N){ for(ll i=2;i*i<=N;++i){if(N%i==0) return false;}return true;}
using namespace std;
int edt(string s1,string s2,int i,int j,vector<vector<int>>&dp){
        if(i==s1.size()){
            return s2.size()-j;
        }
        if(j==s2.size()){
            return s1.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=edt(s1,s2,i+1,j+1,dp);
        }
        else{
            int x=1+edt(s1,s2,i,j+1,dp);
            int y=1+edt(s1,s2,i+1,j,dp);
            int z=1+edt(s1,s2,i+1,j+1,dp);
            return dp[i][j]=min(x,min(y,z));
        }
        
    }
    int editDistance(string s, string t) {
        // Code here
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=edt(s,t,0,0,dp);
        return ans;
        
    }
int main() {
    #ifndef ONLINE_JUDGE
    freopen("dh1.txt","r",stdin);
    freopen ("dh3.txt","w",stdout);
    #endif
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<editDistance(s1,s2)<<endl;

}
