class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mod=1e9+7;
        int start=0,end=n-1;
        long long ans=0;
        
         vector<int> pows(n, 1);
        for (int i = 1 ; i < n ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        while(start<=end){
            if(nums[start]+nums[end]>target){
                //if(nums[end]+nums[end]<=target) ans++;
                end--;
            }
            else{
                cout<<"yha error aa rha h"<<start<<"  "<<end;
                
//k=k%mod;
                ans = (ans+pows[end-start])%mod;
                start++;
                
            }
        }
        return ans%mod;
            
        
    }
};