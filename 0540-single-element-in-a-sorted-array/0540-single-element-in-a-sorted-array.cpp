class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //Exactly one element is single, so it means it has odd length array and 
           int n = nums.size();
        int high=n-1;
        int low=0;
        int mid,left;
        while(low<high){
            mid = (high+low)/2;
            
           //if(high==low) return nums[high];
            if(mid-1>=low && nums[mid]==nums[mid-1]){
                left = mid-1-low;
                if(left%2!=0 && mid-2>=low){ 
                    high=mid-2;
                    
                }
                else{
                low = mid+1;
                }
            }
            else if(mid+1<=high && nums[mid]==nums[mid+1]){
                left = mid-low;
                if(left%2!=0 && mid-1>=low) high = mid-1;
                else low=mid+2;
            }
            else{
                return nums[mid];
            }
        }
        return nums[high];
    }
};