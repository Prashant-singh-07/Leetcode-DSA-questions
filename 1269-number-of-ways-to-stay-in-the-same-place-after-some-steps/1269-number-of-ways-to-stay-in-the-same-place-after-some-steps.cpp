class Solution {
public:
    int mod=1e9+7;
    int fun(int steps,int len,int curr,vector<vector<int>>& dp){
        if(steps==0){
            if(curr==0) return 1;
            return 0;
        }
        if(curr-steps>0) return 0;
        int k=0;
        if(curr-1>=0){
            if(dp[curr-1][steps-1]!=-1) {
                k = (k+dp[curr-1][steps-1])%mod;
                
            }
            
            else{
        k = (k+fun(steps-1,len,curr-1,dp))%mod;
        }
        }
         if(curr+1<len){
             if(dp[curr+1][steps-1]!=-1) {
                k = (k+dp[curr+1][steps-1])%mod;
                
            }
             else{
            
             k = (k+fun(steps-1,len,curr+1,dp))%mod;
             }
         }
         if(dp[curr][steps-1]!=-1) {
                k = (k+dp[curr][steps-1])%mod;
            }
        else{
         k = (k+fun(steps-1,len,curr,dp))%mod;
        }
        return dp[curr][steps]=k;
    }
    int numWays(int steps, int arrLen) {
        int p=steps+1;
        vector<vector<int>> dp(p,vector<int>(p,-1));
        return fun(steps,arrLen,0,dp);
    
    }
};