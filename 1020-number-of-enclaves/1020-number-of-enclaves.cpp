class Solution {
public:
    int count=0;
    int a[4] = {1,0,-1,0};
    int b[4] = {0,1,0,-1};
    void fun(vector<vector<int>>& grid,vector<vector<int>>& vis,int row,int col){
        vis[row][col]=1;
        count++;
        for(int i=0;i<4;i++){
            if(row+a[i]<grid.size() && col+b[i]<grid[0].size() && grid[row+a[i]][col+b[i]]==1 && vis[row+a[i]][col+b[i]]==-1){
                fun(grid,vis,row+a[i],col+b[i]);
            }
        }
        return ;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> v(m,vector<int>(n,-1));
       for(int j=0;j<n;j++){
           if(grid[0][j]==1 && v[0][j]==-1){
               fun(grid,v,0,j);
           }
           if(grid[m-1][j]==1 && v[m-1][j]==-1){
                fun(grid,v,m-1,j);
           }
       }
        
        for(int i=0;i<m;i++){
            if(grid[i][0]==1 && v[i][0]==-1){
                fun(grid,v,i,0);
            }
            if(grid[i][n-1]==1 && v[i][n-1]==-1){
                fun(grid,v,i,n-1);
            }
        }
        int ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) ans++;
            }
        }
        cout<<ans<<"  "<<count<<endl;
        return ans-count;
        
    }
};