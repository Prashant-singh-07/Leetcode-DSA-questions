class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
       vector<bool> dp(n+1,false);
        dp[n]=true;
        if(nums[n-1]==nums[n-2]) dp[n-2]=true;
        for(int i=n-3;i>=0;i--){
            if(nums[i]==nums[i+1]){
                dp[i]=dp[i]|dp[i+2];
                if(nums[i+1]==nums[i+2]){
                    dp[i]=dp[i]|dp[i+3];
                }
            }
            if(nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2]){
                 dp[i]=dp[i]|dp[i+3];
            }
        }
        return dp[0];
    }
};