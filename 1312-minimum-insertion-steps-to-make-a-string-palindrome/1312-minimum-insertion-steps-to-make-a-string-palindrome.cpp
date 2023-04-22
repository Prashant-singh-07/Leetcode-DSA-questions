class Solution {
    private:
    int ans=INT_MAX;
    int fun(string& s,int start,int end,vector<vector<int>>& dp){
        if(start>=end){
            return 0;
        }
        if(dp[start][end]!=-1) return dp[start][end];
        else{
            if(s[start]==s[end]){
                return dp[start][end] = fun(s,start+1,end-1,dp);
            }
            else{
                int k=0;
                k = 1+fun(s,start+1,end,dp);
               k = min(k,1+fun(s,start,end-1,dp));
            return dp[start][end] = k;
            }
        }
        return 0;
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
     return fun(s,0,n-1,dp);  
    }
};