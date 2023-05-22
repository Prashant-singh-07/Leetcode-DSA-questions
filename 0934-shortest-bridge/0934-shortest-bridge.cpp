class Solution {
public:
    vector<vector<int>> vis;
    vector<vector<int>> kinara;
    vector<int> dir = {1,0,-1,0,1};
    int ans=INT_MAX;
    void fun(vector<vector<int>>& grid,int row,int col,int flag){
        
        if(vis[row][col]!=-1) return ;
        int n = grid.size();
        int sum;
        vis[row][col]++;
        int count=0;
        for(int i=0;i<4;i++){
            if(row+dir[i]>=0 && row+dir[i]<n && col+dir[i+1]>=0 && col+dir[i+1]<n && grid[row+dir[i]][col+dir[i+1]]==1 ){
                count++;
                fun(grid,row+dir[i],col+dir[i+1],flag);
            }
        }
        if(count<4){
            if(flag==0){
            kinara.push_back({row,col});
            }
            else{
                for(int i=0;i<kinara.size();i++){
                    sum = abs(row-kinara[i][0]);
                    sum += abs(col-kinara[i][1]);
                    ans = min(ans,sum-1);
                }
            }
        }
        return ;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vis = vector<vector<int>>(n,vector<int>(n,-1));
        //lets go for first round;
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==-1){
                    fun(grid,i,j,flag);
                    flag++;
                }
            }
        }
        return ans;
    }
};