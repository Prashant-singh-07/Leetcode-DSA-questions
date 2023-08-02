class Solution {
    private:
    unordered_map<int,int> m;
    void fun(vector<int>& nums,vector<int>& v,int i,vector<vector<int>>& ans){
        if(v.size() == nums.size()){
            ans.push_back(v);
            return ;
        }
        for(int j = 0;j<nums.size();j++){
            if(m.find(nums[j])==m.end()){
                m[nums[j]] = 1;
            v.push_back(nums[j]);
            fun(nums,v,j+1,ans);
            v.pop_back();
                m.erase(nums[j]);
            }
        }
        return ;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        fun(nums,v,0,ans);
        return ans;
    }
};