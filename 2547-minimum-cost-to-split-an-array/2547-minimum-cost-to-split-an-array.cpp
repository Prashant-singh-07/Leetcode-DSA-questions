class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n = nums.size();
        vector<int> dp(n);
        //we can use dp approach here for solving this problems.
        dp[0]=k;
        int ans,flag=0;
        for(int i=1;i<n;i++){
             ans=INT_MAX;
             flag=0;
            for(int j=i;j>=0;j--){
                if(m[nums[j]]==1) flag++;
                m[nums[j]]++;
                if(m[nums[j]]>1) flag++;
                if(j>0)
                ans = min(ans,flag+k+dp[j-1]);
                else ans = min(ans,flag+k);
            }
            dp[i]=ans;
            m.clear();
        }
        for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        return dp[n-1];
    }
};