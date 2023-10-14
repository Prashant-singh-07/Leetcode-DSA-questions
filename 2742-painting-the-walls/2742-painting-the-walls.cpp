class Solution {
    private:
    int  fun(vector<int>& cost, vector<int>& time,int n, int ind,vector<vector<int>>& dp){
        
        if(n<=0) return 0;
        if(ind==cost.size()) return INT_MAX;
        
        //i have two option here, either i will choose this index or leave it. so first write code for includig it.
        if(dp[n][ind]!=-1) return dp[n][ind];
        int t = time[ind];
        int ans=INT_MAX;
        int x = fun(cost,time,n-1-t,ind+1,dp);
        if(x!=INT_MAX){
        ans = cost[ind]+x;
        }
        
        ans = min(ans,fun(cost,time,n,ind+1,dp));
        
        return dp[n][ind] = ans;
        
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return fun(cost,time,n,0,dp);
    }
};