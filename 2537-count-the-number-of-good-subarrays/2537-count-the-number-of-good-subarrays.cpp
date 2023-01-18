class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        int n = nums.size();
        unordered_map<int,int> m;
        int start=0;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=m[nums[i]];
            m[nums[i]]++;
            while(curr>=k){
                ans+=(n-i);
                curr-=m[nums[start]]-1;
                m[nums[start]]--;
                start++;
            }
        }
        return ans;
    }
};