#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pi pair<ll,ll>
#define mod 1000000007
bool isPrime(ll N){ for(ll i=2;i*i<=N;++i){if(N%i==0) return false;}return true;}
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("a1.txt","r",stdin);
    freopen ("a2.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=51;
    ll prime[n];
    for(ll i=2;i<n;i++){
        prime[i]=1;

    }
    prime[1]=0;
    for(ll i=2;i<n;i++){
        if(prime[i]==1){
            cout<<i<<endl;
            for(ll j=i*2;j<n;j+=i){
                prime[j]=0;
            }
        }
    }
    cout<<prime[4]<<endl;
   
}
