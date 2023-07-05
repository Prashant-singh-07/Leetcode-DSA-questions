class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        vector<int> left(n),right(n);
        int count=0;
        for(int i=0;i<n;i++){
            left[i]=count;
            if(nums[i]==0) count=0;
            else count++;
        }
        count=0;
        for(int i=n-1;i>=0;i--){
            right[i]=count;
            if(nums[i]==0) count=0;
            else count++;
        
        }
        int ans = 0;
//         ans = max(ans,right[1]);
//         ans = max(ans,left[n-1]);
        
        for(int i=0;i<n;i++){
            //cout<<left[i-1]<<"  "<<right[i+1]<<endl;
            ans = max(ans,left[i]+right[i]);
        }
        return ans;
    }
};