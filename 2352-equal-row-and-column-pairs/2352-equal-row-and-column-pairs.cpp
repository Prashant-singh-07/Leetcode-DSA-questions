class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int dummyr,dummyc,count;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dummyr=0;
                dummyc=0;
                count=0;
                while(dummyr<n && dummyc<n && grid[i][dummyc]==grid[dummyr][j]){
                    count++; 
                    dummyc++;
                    dummyr++;
                }
                if(count==n) ans++;
            }
        }
        return ans;
        
        
    }
};