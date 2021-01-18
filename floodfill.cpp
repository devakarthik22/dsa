/*An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.*/
class Solution {
public:
    void bfs(vector<vector<int>>& grid,int newColor,int old,int i,int j,int n,int m){
        if(i<0 or j<0){
            return;
        }
        if(i>=grid.size() or j>=grid[0].size()){
            return;
        }
        if(grid[i][j]!=old){
            return;
        }
        grid[i][j]=newColor;
        bfs(grid,newColor,old,i+1,j,n,m);
        bfs(grid,newColor,old,i-1,j,n,m);
        bfs(grid,newColor,old,i,j+1,n,m);
        bfs(grid,newColor,old,i,j-1,n,m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor){
            return image;
        }
        int n=image.size();
        int m=image[0].size();
        int old=image[sr][sc];
        bfs(image,newColor,old,sr,sc,n,m);
        return image;
        
    }
};
