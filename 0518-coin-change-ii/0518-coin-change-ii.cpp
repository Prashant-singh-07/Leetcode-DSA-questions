class Solution {
    int fun(int amount,vector<int>& coins,vector<vector<int>>& dp,int ind){
        if(amount==0) return 1;
        if(ind==coins.size()) return 0;
        int ans=0;
        if(dp[amount][ind]!=-1) return dp[amount][ind];
         if(amount>=coins[ind]){
             ans+=fun(amount-coins[ind],coins,dp,ind);
         }
        ans+=fun(amount,coins,dp,ind+1);
        return dp[amount][ind] = ans;
    }
    
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(),-1));
        sort(coins.begin(),coins.end(),greater<int>());
        return fun(amount,coins,dp,0);
    }
};