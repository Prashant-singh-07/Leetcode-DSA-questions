class Solution {
public:
    int mod =1e9+7;
    int fun(int n,int k,int target,vector<vector<int>>& dp){
        if(n==0){
            if(target==0) return 1;
            return 0;
        }
        if(target<=0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        long long ans=0;
        for(int i=1;i<=k;i++){
            if(target>=i)
            ans+=fun(n-1,k,target-i,dp);
            ans%=mod;
        }
        return dp[n][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return fun(n,k,target,dp);
    }
};