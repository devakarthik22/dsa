/*Given a Directed Graph. Count the total number of ways or paths that exist between two vertices in the directed graph. These paths doesn’t contain any cycle.
Note: Graph doesn't contain multiple edges, self loop and cycles and the two vertices( source and destination) are denoted in the example.*/
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
void dfs(vector<int> g[],int x,int des,int &c){
        if(x==des){
            c++;
        }
        for(int i:g[x]){
            dfs(g,i,des,c);
        }
        
    }
int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        bool visited[V+1]={false};
        int c=0;
        dfs(adj,source,destination,c);
        return c;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("a1.txt","r",stdin);
    freopen ("a2.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        vector<int> g[v];
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            g[x].pb(y);
            //g[y].pb(x);

        }
        int s,d;
        cin>>s>>d;
        cout<<countPaths(v,g,s,d)<<endl;
    }
    
}
