class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
     long long ans=0;
        int i=0;
        int flag1=0,flag2=0;
        int start=-1,end1,end2,end;
        while(i<nums.size()){
            if(nums[i]<minK || nums[i]>maxK){
                //reset system
                flag1=0;
                flag2=0;
                start=-1;
            }
            else{
                if(nums[i]==minK) flag1++,end1=i;
                if(nums[i]==maxK) flag2++,end2=i;
                if(start==-1) start=i;
                
            }
            if(flag1>0 && flag2>0){
                //cout<<i<<endl;
                end = min(end1,end2);
                ans+=(end-start+1);
            }
            i++;
        }
        return ans;
    }
};