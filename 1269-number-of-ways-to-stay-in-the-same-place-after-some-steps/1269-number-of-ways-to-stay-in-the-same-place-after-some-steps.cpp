class Solution {
    private:
    int mod=1e9+7l;
    int fun(int ind,int steps,int len,vector<vector<int>>& dp){
        if(steps==0){
            if(ind==0) return 1;
            return 0;
        }
        if(ind>=len || ind<0 || ind>steps) return 0;
        if(dp[ind][steps]!=-1) return dp[ind][steps];
        long long k = fun(ind+1,steps-1,len,dp);
        k+=fun(ind-1,steps-1,len,dp);
        k+=fun(ind,steps-1,len,dp);
        return dp[ind][steps]=k%mod;
    }
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+1,vector<int>(steps+1,-1));
        return fun(0,steps,arrLen,dp);
    }
};