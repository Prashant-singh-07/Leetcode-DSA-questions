class Solution {
public:
    int minimumTime(string s) {        
        int n = s.size();
        vector<int> dp(n+1);
        int last=0;
        if(s[0]=='0') dp[0]=0;
        else dp[0]=1,last=1;
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                
                dp[i]=dp[i-1];
                
            }
            else{
                dp[i] = min(i+1,2+last);
                last = dp[i];
            }
        }
        vector<int> right(n+1);
        if(s[n-1]=='0') right[n-1]=0;
        else right[n-1]=1,last=1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0'){
                right[i]=right[i+1];
            }
            else{
                right[i] = min(n-i,2+last);
                last = right[i];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                ans = min(ans,dp[i]+right[i+1]);
            }
        }
     ans=min(ans,dp[n-1]);    
    ans=min(ans,right[0]);
        return ans;
        
    }
};