class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
             int n = nums.size();
             int mid = n/2;
             long long ans=0;
             
             ans += abs(nums[mid]-k);
             
             for(int i=0;i<nums.size();i++){
                 if(i<mid && nums[i]>k) ans+= (nums[i]-k);
                 else if(i>mid && nums[i]<k) ans+= (k-nums[i]);
             }
             return ans;
    }
};