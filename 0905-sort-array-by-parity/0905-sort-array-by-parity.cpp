class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start=0,end=0,temp;
        while(end<nums.size()){
            if(nums[end]%2==0){
                temp=nums[end];
                nums[end]=nums[start];
                nums[start]=temp;
                start++;
            }
            end++;
        }
        return nums;
    }
};