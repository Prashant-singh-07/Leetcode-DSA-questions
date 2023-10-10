class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        vector<int> fresh;
        for(auto i:s) fresh.push_back(i);
        int start,last,uppu;
        sort(fresh.begin(),fresh.end());
        int n = nums.size();
        int ans=INT_MAX;
        for(int i=0;i<fresh.size();i++){
            start=fresh[i];
            last = start+n-1;
            uppu = upper_bound(fresh.begin(),fresh.end(),last) - fresh.begin();
            ans = min(ans,n-uppu+i);
        }
        return ans;
    }
};