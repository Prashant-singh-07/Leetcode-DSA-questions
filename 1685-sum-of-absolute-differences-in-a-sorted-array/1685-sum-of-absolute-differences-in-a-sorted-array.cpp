class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            left[i]+=nums[i];
            left[i]+=left[i-1];
        }
        right[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]+=nums[i];
            right[i]+=right[i+1];
        }
        vector<int> ans(n);
        int k =0;
        for(int i=0;i<n;i++){
            if(i-1>=0){
                k = i*nums[i];
                ans[i]+=abs(k-left[i-1]);
            }
            if(i+1<n){
                k = (n-i-1)*nums[i];
                ans[i]+=abs(k-right[i+1]);
            }
        }
        return ans;
    }
};