class Solution {
public:
    vector<vector<int>> ans;
    map<vector<int>,int> m;
    void fun(vector<int>& nums,int i,vector<int>& v){
        
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]>=nums[i]){
                v.push_back(nums[j]);
                if(m.find(v)==m.end()){
                ans.push_back(v);
                    m[v]++;
                }
                fun(nums,j,v);
                v.pop_back();
            }
        }
        return ;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
            fun(nums,i,v);
            v.pop_back();
        }
        return ans;
    }
};