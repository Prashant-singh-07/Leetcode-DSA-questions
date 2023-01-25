class Solution {
public:
   bool check(string s){
        int l=0;
       int r=s.size()-1;
       while(l<r){
           if(s[l]!=s[r]) return false;
           l++;
           r--;
       }
        return true;
    }
    
    int countSubstrings(string s) {
        int ans=0;
        int n = s.size();
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i-j==0) dp[i][0]=true,ans++;
                else if(s[i]==s[j]){
                    if(i-j==1) dp[i][1]=true,ans++;
                    else{
                        if(dp[i-1][i-j-2]) dp[i][i-j]=true,ans++;
                        else dp[i][i-j]=false;
                    }
                }
            }
        }
        return ans;
    }
};