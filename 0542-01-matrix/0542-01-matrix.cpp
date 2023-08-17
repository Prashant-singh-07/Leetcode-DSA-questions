class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i+1<m && mat[i+1][j]==0) || (j+1<n && mat[i][j+1]==0) || (i-1>=0 && mat[i-1][j]==0) || (j-1>=0 && mat[i][j-1]==0)){
                    vis[i][j]=true;
                    q.push({i,j});
                } 
                   }
        }
        int row,col;
    
        while(!q.empty()){
            
            row=q.front().first;
            col=q.front().second;
            q.pop();
            if(row+1<m && mat[row+1][col]==1 && vis[row+1][col]==false){
                mat[row+1][col]=mat[row][col]+1;
                vis[row+1][col]=true;
                q.push({row+1,col});
            }
             if(col+1<n && mat[row][col+1]==1 && vis[row][col+1]==false){
                mat[row][col+1]=mat[row][col]+1;
                  q.push({row,col+1});
                vis[row][col+1]=true;
            }
             if(row-1>=0 && mat[row-1][col]==1 && vis[row-1][col]==false){
                mat[row-1][col]=mat[row][col]+1;
                  q.push({row-1,col});
                vis[row-1][col]=true;
            }
             if(col-1>=0 && mat[row][col-1]==1 && vis[row][col-1]==false){
                mat[row][col-1]=mat[row][col]+1;
                  q.push({row,col-1});
                vis[row][col-1]=true;
            }
        }
        return mat;
    }
};