class Solution {
    int fun(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& dp){
        if(row>=grid.size() || row<0 || col>=grid[0].size() || col<0 || grid[row][col]==1) return 0;
        
        if(row==grid.size()-1 && col==grid[0].size()-1) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        // if i am at any index, then i have two option
       int ans = fun(grid,row+1,col,dp);
        ans += fun(grid,row,col+1,dp);
        return dp[row][col] = ans;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return fun(grid,0,0,dp);
    }
};