class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int mid;
        while(low<=high){
        mid = (low+ ((high-low)/2));
        if(nums[mid]==target) return true;
        if((nums[low]==nums[mid]) && (nums[high]==nums[mid])){
            low++;
            high--;
        }
            
        
        else if(nums[low]<=nums[mid]){
            if(target<nums[mid] && target>=nums[low]) high=mid-1;
            else low=mid+1;
        }
        else{
            if(target<=nums[high] && nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        }
        return false;
    }
};