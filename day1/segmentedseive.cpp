//for large queries of l to r
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pi pair<ll,ll>
#define mod 1000000007
#define ma 100002
bool sPrime(ll N){ for(ll i=2;i*i<=N;++i){if(N%i==0) return false;}return true;}
using namespace std;
vector<ll> primes(){
    bool arr[ma];
    for(ll i=0;i<ma;i++){
        arr[i]=1;
    }
    arr[1]=0;
    arr[1]=0;
    for(ll i=2;i<=ma;i++){
        if(arr[i]==1){
            for(ll j=2*i;j<=ma;j+=i){
                arr[j]=0;
            }
        }
    }
    vector<ll> ans;
    //cout<<1<<endl;
    for(ll i=1;i<=ma;i++){
        if(arr[i]==1){
            ans.pb(i);
        }
    }
    //cout<<1<<endl;
    return ans;
}
void printprimes(ll n,ll m,vector<ll> &p){
    bool isprime[m-n+1];
    for(ll i=0;i<(m-n+1);i++){
        isprime[i]=1;
    }
    for(auto x:p){
        //cout<<curr<<endl;
        if(x*x<m){
            ll curr=x;
            ll y=(n/curr)*curr;
            if(y<n){
                y+=curr;
            }
            for(ll j=y;j<=m;j+=y){
             isprime[j-n]=0;
            }
            if(y==curr){
                isprime[y-n]=1;
            }
            //cout<<x<<endl;
        }
    }
    //cout<<2<<endl;
    for(ll i=0;i<(m-n+1);i++){
        if(isprime[i]==1){
            if(i+n==1){
                continue;
            }
            cout<<i+n<<endl;
        }
    }
    cout<<endl;
}


int main() {
     #ifndef ONLINE_JUDGE
    freopen("a1.txt","r",stdin);
    freopen ("a2.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
     vector<ll> prime=primes();
    while(t--){
        ll n,m;
        cin>>n>>m;
        //cout<<2<<endl;
        printprimes(n,m,prime);


    }
}
