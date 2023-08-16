class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        //vector<int> temp=nums;
        sort(nums.begin(),nums.end());
        //int n = nums.size();
        int ans=0,curr=0;
        int j;
        for(int i=0;i<nums.size();i++){
            j=i;
            while(j<nums.size() && nums[j]==nums[i]){
                if(curr>0){
                    ans++;
                    curr--;
                }
                j++;
            }
            curr+=(j-i);
            i=j-1;
        }
        return ans;
    }
};