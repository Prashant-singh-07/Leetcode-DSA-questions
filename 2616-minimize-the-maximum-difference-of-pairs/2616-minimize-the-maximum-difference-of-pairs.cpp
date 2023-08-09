class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low = 0;
        int n = nums.size();
         int high = nums[n-1]-nums[0];
        int mid,count=0,i;
        while(low<high){
            mid = ((low+high)/2);
            count=0;
            for(i=0;i<n-1;i++){
                if(nums[i+1]-nums[i]<=mid){
                    count++;
                    i++;
                    if(count>=p){
                        break;
                    }
                }
            }
            if(count>=p){
                high=mid;
            }
            else low=mid+1;
        }
        return low;
    }
};