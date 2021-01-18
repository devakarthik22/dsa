/*You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.*/
class Solution {
public:
    bool isvalid(vector<vector<int>>& grid,int x,int y){
        int n=grid.size();
        int m=grid[0].size();
        if(x>=0 and y>=0 and x<n and y<m and grid[x][y]==1){
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid){
        int unrotten=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> v={{1,0},{-1,0},{0,-1},{0,1}};
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
                if(grid[i][j]==1){
                    unrotten++;
                }
            }
        }
        while((!q.empty()) and unrotten>0){
            int z=q.size();
            ans++;
            for(int i=0;i<z;i++){
                pair<int,int> p=q.front();
                q.pop();
                for(int j=1;j<=4;j++){
                    int x=v[j-1][0]+p.first;
                    int y=v[j-1][1]+p.second;
                    if(isvalid(grid,x,y)){
                        grid[x][y]=2;
                        q.push(make_pair(x,y));
                        unrotten--;
                    }
                }
                
            }
        }
        if(unrotten==0){
            return ans;
        }
        else{
            return -1;
        }
        
        
    }
};
