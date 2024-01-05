class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ind;
        vector<int> dp(n,INT_MAX);
        for(int i=0;i<nums.size();i++){
            ind = upper_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
            if(ind>0){
                if(dp[ind-1]<nums[i]) dp[ind]=nums[i];
            }
            else dp[ind]=nums[i];
        }
        for(int i=n-1;i>=0;i--) {
            if(dp[i]!=INT_MAX) return i+1;
        }
        return 0;
    }
};