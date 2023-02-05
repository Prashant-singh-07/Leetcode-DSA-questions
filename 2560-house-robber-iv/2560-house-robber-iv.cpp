class Solution {
public:
    int check(vector<int>& nums,int mid){
        int last=-2;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid && last!=i-1){
                last=i;
                count++;
            }
        }
        return count;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int low=*min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        int mid;
        int ans=-1;
        while(low<=high){
            mid = (low+high)/2;
            if(check(nums,mid)>=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};