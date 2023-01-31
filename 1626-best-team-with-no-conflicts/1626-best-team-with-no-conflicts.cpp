class Solution {
public:
   
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
           vector<pair<int,int>> v;
        int n = ages.size();
        for(int i=0;i<ages.size();i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end());
        vector<int> dp(n,0);
        dp[0]=v[0].second;
        int m = INT_MIN,ans=dp[0];
        for(int i=1;i<n;i++){
             m = INT_MIN;
            for(int j=0;j<i;j++){
                if(v[j].second<=v[i].second){
                    m = max(m,dp[j]+v[i].second);
                }
            }
            dp[i]=max(m,v[i].second);
            ans=max(ans,dp[i]);
        }
        return ans;
        
    }
};