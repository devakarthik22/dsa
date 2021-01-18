//question//
//Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.//
class Solution {
public:
    void Dfs(vector<vector<char>>& grid,int i,int j,int n,int m){
        if(i<0 or j<0){
            return;
        }
        if(i>=n or j>=m){
            return;
        }
        if(grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        Dfs(grid,i+1,j,n,m);
        Dfs(grid,i-1,j,n,m);
        Dfs(grid,i,j+1,n,m);
        Dfs(grid,i,j-1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    Dfs(grid,i,j,n,m);
                    ans++;
                }
            }
        }
        return ans; 
    }
};
