class Solution {
    int fun(vector<int>& nums,int curr,vector<int>& dp,int target,int mask){
        int n = nums.size();
        int k = pow(2,n);
        if(mask==k-1) return 0;
        
        int ans=0,sum;
        if(dp[mask]!=-1) return dp[mask];
        int temp;
        for(int i=0;i<nums.size();i++){
            temp = 1<<i;
            if(temp&mask) continue;
            sum=curr+nums[i];
            if(sum==target){
                ans = max(ans,1+fun(nums,0,dp,target,mask|temp));
            }
            else if(sum>target) continue;
            else{
                ans = max(ans,fun(nums,sum,dp,target,mask|temp));
            }
        }
        return dp[mask] = ans;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%k!=0) return false;
        int n = nums.size();
        vector<int> dp(1<<(n+1),-1);
        int target = sum/k;
        return k==fun(nums,0,dp,target,0);
    }
};