class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> v(n+1);
        for(int i=0;i<paths.size();i++){
                v[paths[i][0]].push_back(paths[i][1]);
                v[paths[i][1]].push_back(paths[i][0]);
            }
        vector<int> ans(n);
        ans[0]=1;
        vector<int> check(4,0);
        for(int i=2;i<=n;i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]<i){
                    check[ans[v[i][j]-1]-1]++;
                }
            }
            if(check[0]==0) ans[i-1]=1;
            else if(check[1]==0) ans[i-1]=2;
            else if(check[2]==0) ans[i-1]=3;
            else ans[i-1]=4;
            
            check[0]=0;
            check[1]=0;
            check[2]=0;
            check[3]=0;
        }
        return ans;
        
    }
};