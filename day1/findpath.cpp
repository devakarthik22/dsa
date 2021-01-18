/*Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector <vector <int>> &grid,vector <vector <bool>>& vis,int x,int y,int n)
    {
        if(x>=n || x<0 || y>=n || y<0|| vis[x][y]==true || grid[x][y]==0)
                return;
        vis[x][y]=true;
        dfs(grid,vis,x+1,y,n);
        dfs(grid,vis,x-1,y,n);
        dfs(grid,vis,x,y+1,n);
        dfs(grid,vis,x,y-1,n);
    }
    bool is_Possible(vector<vector<int>>& grid) {
        int n=grid.size();
        vector <vector <bool>> vis(n,vector <bool>(n,false));
        int sx,sy,dx,dy;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    sx=i;
                    sy=j;
                }
                else if(grid[i][j]==2)
                {
                    dx=i;
                    dy=j;
                }
            }
        }
        dfs(grid,vis,sx,sy,n);
        return vis[dx][dy];
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> grid(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
            
        }
        Solution obj;
        bool ans=obj.is_Possible(grid);
        cout<<((ans)?"1\n":"0\n");
    }
    return 0;
}
 
