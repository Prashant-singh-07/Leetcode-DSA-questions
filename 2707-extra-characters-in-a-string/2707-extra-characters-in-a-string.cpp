class Solution {
public:
    int minExtraChar(string s, vector<string>& d) {
        unordered_map<string,int> m;
        for(int i=0;i<d.size();i++) m[d[i]]++;
        string temp;
        int count=0;
        vector<int> dp(s.size(),INT_MAX);
        for(int i=0;i<s.size();i++){
            for(int j=i;j>=0;j--){
                temp = s.substr(j,i-j+1);
                if(m[temp]>0){
                    if(j>0) dp[i]=min(dp[i],dp[j-1]);
                    else dp[i]=0;  
                }
            }
            
                if(i>0) count=dp[i-1];
                dp[i]=min(dp[i],1+count);
            
            //cout<<dp[i]<<"  ";
        }
        return dp[s.size()-1];
    }
};