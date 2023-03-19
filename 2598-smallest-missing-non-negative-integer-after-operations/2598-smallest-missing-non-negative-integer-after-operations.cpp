class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> res(value,0);
        for(int i=0;i<nums.size();i++){
            nums[i]= ((nums[i]%value)+value)%value;  
            res[nums[i]]++;
        }
         int minIdx = min_element(begin(res), end(res)) - begin(res);
    return minIdx + res[minIdx]*value;
    }
};