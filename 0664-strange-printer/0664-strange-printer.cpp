class Solution {
public:
    int strangePrinter(string s) {
        if(s.size()==0) return 0;
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i<n-1){
                if(s[i]==s[i+1]) dp[i][i+1]=1;
                else dp[i][i+1]=2;
            }
        }
        int temp;
        for(int len=2;len<n;len++){
            for(int k=0;k+len<n;k++){
                dp[k][k+len]=len+1;
                for(int mid=0;mid<len;mid++){
                 temp = dp[k][k+mid]+dp[k+mid+1][len+k];
                    if(s[k+mid]==s[len+k]) temp--;
                    dp[k][k+len]=min(dp[k][k+len],temp);
                }
            }
        }
        return dp[0][n-1];
    }
};