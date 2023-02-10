class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int l=grid.size();
        int m = grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int i,j,k;
        int ans=-1;
        if(q.size()==(l*m)) return -1;
        while(!q.empty()){
            int n = q.size();
            ans++;
            i=0;
            while(i<n){
                pair<int,int> p= q.front();
                q.pop();
                j=p.first;
                k=p.second;
                
                if(j+1 < l && grid[j+1][k]==0){
                    q.push({j+1,k});
                grid[j+1][k]=1;
                }
                 if(k+1 < m && grid[j][k+1]==0){
                     q.push({j,k+1});
                 grid[j][k+1]=1;
                 }
                 if(k-1 >= 0 && grid[j][k-1]==0){ 
                     q.push({j,k-1});
                 grid[j][k-1]=1;
                 }
                 if(j-1 >= 0 && grid[j-1][k]==0){ 
                     q.push({j-1,k});
                 grid[j-1][k]=1;
                 }
                
                
                i++;
                
            }
            
        }
        return ans;
    }
};