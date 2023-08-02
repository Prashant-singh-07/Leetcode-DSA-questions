class Solution {
    private:
    int fun(string& s1,string& s2,int m,int n,vector<vector<int>>& dp){
        if(m<0 && n<0){
            return 0;
        }
        int k,p=INT_MAX,r=INT_MAX;
        int ans=INT_MAX;
         if(dp[m+1][n+1]!=-1) return dp[m+1][n+1];
        string temp,tempu;
        if(m>=0 && n>=0){
        if(s1[m]==s2[n]){
            return fun(s1,s2,m-1,n-1,dp);
        }
        }
        if(m>=0){
         k = 97+(s1[m]-'a');
        p = k+fun(s1,s2,m-1,n,dp);
        }
        if(n>=0){
         k = 97+(s2[n]-'a');
        r = k+fun(s1,s2,m,n-1,dp);
        }
        
        return dp[m+1][n+1] = min(p,r);
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return fun(s1,s2,m-1,n-1,dp);
    }
};