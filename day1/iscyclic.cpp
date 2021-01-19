/*Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.*/
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
bool iscycle(int node,vector<int> g[],int parent,bool visited[]){
    visited[node]=true;
    int x=node;
    for(auto i: g[x]){
        if(!visited[i]){
            bool a=iscycle(i,g,x,visited);
            if(a){
                return true;
            }
        }
        else if(i!=parent){
            return true;
        }
    }
    return false;
    
}
bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   bool visited[V+1]={false};
   for(int i=0;i<V;i++){
       if(!visited[i]){
           if(iscycle(i,g,-1,visited)){
               return true;
           }
       }
   }
   return false;
}
int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("a1.txt","r",stdin);
    //freopen ("a2.txt","w",stdout);
    //#endif
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
            g[y].pb(x);

        }
        cout<<isCyclic(g,v)<<endl;
    }
    
}
