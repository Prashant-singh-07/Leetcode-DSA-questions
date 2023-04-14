class Solution {
    private:
    int fun(string& s,int start,int end,vector<vector<int>>& dp){
        if(start>=end){
            if(start>end) return 0;
            else return 1;
        }
        if(dp[start][end]!=-1) return dp[start][end];
        int ans=-1;
        if(s[start]==s[end]){
            ans = 2+fun(s,start+1,end-1,dp);
        }
        else{
            ans = max(ans,fun(s,start+1,end,dp));
            ans = max(ans,fun(s,start,end-1,dp));
        }
        return dp[start][end]=ans;
    }
public:
    int longestPalindromeSubseq(string s) {
        // a string give, find a longest palindromic subsequences.
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fun(s,0,n-1,dp);
    }
};