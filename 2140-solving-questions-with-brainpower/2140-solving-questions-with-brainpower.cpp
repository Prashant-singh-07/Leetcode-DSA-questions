class Solution {
public:
    long long mostPoints(vector<vector<int>>& question) {
        int n = question.size();
        vector<long long> dp(n);
        dp[n-1]=question[n-1][0];
        long long ans=dp[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i]=question[i][0];
            if(i+question[i][1]+1<n){
                dp[i]+=dp[i+question[i][1]+1];
            }
            if(dp[i+1]>dp[i]){
                dp[i]=dp[i+1];
            }
            if(dp[i]>ans){
                ans=dp[i];
            }
        }
        return ans;
    }
};