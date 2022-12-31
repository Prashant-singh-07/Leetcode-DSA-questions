class Solution {
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int ind1,ind2;
        vector<int> ans(2); 
        for(int i=0;i<nums.size();i++){
            ind1=i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ind2=j;
                    ans[0]=ind1;
                    ans[1]=ind2;
                    return ans;
                }
              
            }
        }
        return ans;
    }
};