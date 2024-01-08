class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long,long>> dp(nums.size());
        int ans=0;
        long long diff;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                diff = (long)nums[i]- (long)nums[j];
                ans+=dp[j][diff];
                dp[i][diff]+=dp[j][diff];
                dp[i][diff]++;
            }
        }
        
        return ans;
    }
};