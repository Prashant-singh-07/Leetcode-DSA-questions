class Solution {
public:
    int jump(vector<int>& nums) {
        int start=0,end=0,temp,step=0;
       while(end<nums.size()-1){
           temp=INT_MIN;
        for(int i=start;i<=end;i++){
            temp=max(temp,i+nums[i]);
        }
           start=end+1;
           end=temp;
           step++;
       }
        return step;
    }
};