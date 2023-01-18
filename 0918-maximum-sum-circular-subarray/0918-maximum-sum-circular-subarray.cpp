class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int res=INT_MIN;
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            res=max(res,curr);
            if(curr<0) curr=0;
        }
        
        vector<int> high(n);
        int sum=nums[n-1];
        high[n-1]=nums[n-1];
        for(int i=n-2;i>0;i--){
           sum+=nums[i];
            high[i]=max(high[i+1],sum);
        }
        sum=0;
        for(int i=0;i<n-1;i++){
            sum+=nums[i];
            res = max(res,sum+high[i+1]);
        }
        return res;
    }
};