class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0,high=nums.size()-1;
        int mid;
        while(start<=high){
            mid = (start+high)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                if(nums[start]<nums[high]) high=mid-1;
                else{
                    if(nums[start]>target) start++;
                    else high--;
                }
            }
            else {
                 if(nums[start]<nums[high]) start=mid+1;
                else{
                    if(nums[start]>target) start++;
                    else high--;
                }
            }
        }
        return -1;
    }
};