class Solution {
    private:
    int fun(vector<int>& v,int d,int ind,vector<vector<int>>& dp){
        if(d==0 && ind==v.size()) return 0;
        if(d==0 || ind==v.size()) return INT_MAX;
        if(dp[ind][d]!=-1) return dp[ind][d];
        int k =INT_MIN;
        int j;
        int ans=INT_MAX;
        for(int i=ind;i<v.size();i++){
            k = max(k,v[i]);
            j = fun(v,d-1,i+1,dp);
            if(j!=INT_MAX){
                ans = min(ans,j+k);
            }
        }
       // if(ans==INT_MIN) return INT_MAX;
        return dp[ind][d] = ans;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int i=0;
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
        int ans = fun(jobDifficulty,d,i,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};