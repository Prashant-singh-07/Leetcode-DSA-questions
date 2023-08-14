class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k==0) return nums[0];
        //if(nums.size()<=1) return -1;
        int ans=-1,prev=-1,curr;
        int i;
      if(nums.size()==1){
          if(k%2==0) return nums[0];
          return -1;
      }
         for(i=0;i<nums.size() && k>1;i++){
             if(k>1){
                 k--;
                 prev=max(nums[i],prev);
             }
         }
        if(prev==-1) {
            if(nums.size()>0) return nums[1];
            return -1;
        }
        if(i+1<nums.size()) prev=max(prev,nums[i+1]);
        return prev;
    }
};