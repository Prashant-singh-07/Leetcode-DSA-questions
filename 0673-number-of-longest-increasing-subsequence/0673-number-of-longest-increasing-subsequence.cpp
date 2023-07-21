class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> dp(n,{1,1});
        dp[0]={1,1};
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                   if(dp[i].first == 1+dp[j].first){
                       dp[i].second+=dp[j].second;
                   }
                    else if(dp[i].first < 1+dp[j].first){
                        dp[i].first=1+dp[j].first;
                        dp[i].second=dp[j].second;
                    }
                }
            }
        }
        int ans=0,count=0;
        for(int i=0;i<n;i++){
            if(dp[i].first>ans){
                ans=dp[i].first;
                count=dp[i].second;
            }
            else if(dp[i].first==ans){
                count+=dp[i].second;
            }
        }
        return count;
    }
};