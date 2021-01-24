/*In the country of Rome, Chess is a royal game. For evey move the players had to give some bucks to the Emperor Jurg. The LGMs or Little Green Men, are very good player of chess. But as the chess is a expensive game, thats why it is royal, they asked you to help them find the minimum bucks which they had to pay for moving their Knight from one position to another. Any number of steps can be used to reach the destination.

Constraints:

The chess has a dimension of 8X8, and the index of left bottom cell (0, 0).

Knight move only in a standard way, i.e. 2 row and 1 col or 1 row and 2 col.

If in a step Knight move from (a, b) to (c, d), then LGM had to pay a*c + b*d bucks to Emperor Jurg.

0 ≤ a, b, c, d ≤ 7*/
#include <bits/stdc++.h>
#define ll int
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
using namespace std;
ll mat[10][10];
ll vis[10][10];
ll a1[] = {-1, -2, -2, -1, 1, 2, 2, 1};
ll b1[] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool isvalid(ll x,ll y){
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}
ll calc(ll a,ll b,ll c,ll d){
    return (a*c+b*d);
}
ll djs(ll a,ll b,ll c,ll d){
     priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> q;
     q.push(mp(0,mp(a,b)));
     pair<ll,pair<ll,ll>> p;
     pair<ll,ll> p1;
     while(!q.empty()){
        p=q.top();
        q.pop();
        p1=p.second;
        ll x=p1.first;
        ll y=p1.second;
        //cout<<x<<" "<<y<<endl;
        if(vis[x][y]==1){
            //cout<<1<<endl;
            continue;
        }
        vis[x][y]=1;
        for(ll j=0;j<8;j++){
            ll tx=x+a1[j];
            ll ty=y+b1[j];
            //cout<<tx<<" "<<ty<<" "<<isvalid(tx,ty)<<" "<<calc(x,y,tx,ty)<<endl;
            if(isvalid(tx,ty)){
                if(mat[x][y]+calc(x,y,tx,ty)<mat[tx][ty]){
                    mat[tx][ty]=mat[x][y]+calc(x,y,tx,ty);
                    q.push(mp(mat[tx][ty],mp(tx,ty)));
                }
            }

        }
     }
    return ((mat[c][d] == INT_MAX) ? -1 : mat[c][d]);

}
int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("a1.txt","r",stdin);
    //freopen ("a2.txt","w",stdout);
    //#endif
    ll a,b,c,d;
    while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF){
        for(ll i=0;i<8;i++){
            for(ll j=0;j<8;j++){
                mat[i][j]=INT_MAX;
            }
        }
        for(ll i=0;i<8;i++){
            for(ll j=0;j<8;j++){
                vis[i][j]=0;
            }
        }

        mat[a][b]=0;
        cout<<djs(a,b,c,d)<<endl;
    }
    
}
