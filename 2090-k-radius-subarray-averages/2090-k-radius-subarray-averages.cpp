class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sum(n+1,0);
        sum[1]=nums[0];
        for(int i=1;i<nums.size();i++){
            sum[i+1]=sum[i]+nums[i];
        }
        vector<int> ans(n,-1);
        int div = (k*2)+1;
        for(int i=k;i<n-k;i++){
            ans[i] = (sum[i+k+1]-sum[i-k])/div;
        }
        return ans;
        
    }
};