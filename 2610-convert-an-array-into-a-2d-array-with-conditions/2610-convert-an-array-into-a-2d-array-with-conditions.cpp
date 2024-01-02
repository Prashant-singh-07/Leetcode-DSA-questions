class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            v[nums[i]-1]++;
            if(ans.size()>=v[nums[i]-1]) ans[v[nums[i]-1]-1].push_back(nums[i]);
            else ans.push_back({nums[i]});
        }
        return ans;
    }
};