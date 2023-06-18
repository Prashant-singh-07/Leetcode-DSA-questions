class Solution {
    vector<vector<int>> dp;
    int mod=1e9+7;
    int fun(vector<vector<int>>& grid,int row,int col,vector<vector<bool>>& vis){
        
        
        if(dp[row][col]!=-1) return dp[row][col];
        vis[row][col]=true;
        int ans=0;
        if(row+1<grid.size() && !vis[row+1][col] && grid[row+1][col]>grid[row][col]){
            ans+=fun(grid,row+1,col,vis);
            ans %=mod;
        }
        if(row-1>=0 && !vis[row-1][col] &&  grid[row-1][col]>grid[row][col]){
            ans+=fun(grid,row-1,col,vis);
            ans %=mod;
        }
        if(col+1<grid[0].size() && !vis[row][col+1] && grid[row][col+1]>grid[row][col]){
            ans+=fun(grid,row,col+1,vis);
            ans %=mod;
        }
        if(col-1>=0 && !vis[row][col-1] && grid[row][col-1]>grid[row][col]){
            ans+=fun(grid,row,col-1,vis);
            ans %=mod;
        }
        vis[row][col]=false;
        return dp[row][col] = ans+1;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        dp.resize(n,vector<int>(m,-1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans+=fun(grid,i,j,vis);
                ans %=mod;
            }
        }
        return ans;
        
    }
};