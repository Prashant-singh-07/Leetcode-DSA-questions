class Solution {
public:
    bool check(vector<vector<int>>& cells,int row,int col,int dayat){
        vector<vector<int>> grid(row,vector<int>(col,0));
        for(int i=0;i<dayat;i++) grid[cells[i][0]-1][cells[i][1]-1]=1;
        queue<pair<int,int>> q;
        for(int i=0;i<col;i++){
             if(grid[0][i]==0) q.push({0,i});
        }
        int dir[5] = {-1,0,1,0,-1};
        int cr,cc;
        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            if(r==row-1) return true;
            for(int i=0;i<4;i++){
                cr = r+dir[i];
                cc = c+dir[i+1];
                if(cr>=0 && cc>=0 && cr<row && cc<col && grid[cr][cc]==0){
                    grid[cr][cc]=1;
                    q.push({cr,cc});
                }
            }
        }
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left=0,right=cells.size()-1;
        int mid;
        int ans=0;
        while(left<=right){
            mid = (left+right)/2;
            if(check(cells,row,col,mid)){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};