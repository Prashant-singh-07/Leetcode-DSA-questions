class Solution {
    int fun(vector<vector<int>>& v,int m,int n,int zc,int oc,int i,vector<vector<vector<int>>>& dp){
        
        if(i>=v.size()) return 0;
        // I have two option here.
        int ans=0;
        if(dp[zc][oc][i]!=-1) return dp[zc][oc][i];
        
        if(zc+v[i][0]<=m && oc+v[i][1]<=n){
            ans = 1+fun(v,m,n,zc+v[i][0],oc+v[i][1],i+1,dp);
        }
        ans = max(ans,fun(v,m,n,zc,oc,i+1,dp));
        return dp[zc][oc][i] = ans;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int zc=0,oc=0,k;
        int ans=0;
        k = strs.size();
        vector<vector<int>> v;
        for(int i=0;i<strs.size();i++){
            zc=0;
            oc=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0') zc++;
                else oc++;
            }
            v.push_back({zc,oc});
        }
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(k,-1)));
        return fun(v,m,n,0,0,0,dp);
    }
};