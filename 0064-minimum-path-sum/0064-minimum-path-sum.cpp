class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int k;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                k=INT_MAX;
                if(i-1>=0) k=min(k,grid[i][j]+grid[i-1][j]);
                if(j-1>=0) k = min(k,grid[i][j]+grid[i][j-1]);
                if(k!=INT_MAX) grid[i][j]=k;
            }
        }
        return grid[m-1][n-1];
    }
};