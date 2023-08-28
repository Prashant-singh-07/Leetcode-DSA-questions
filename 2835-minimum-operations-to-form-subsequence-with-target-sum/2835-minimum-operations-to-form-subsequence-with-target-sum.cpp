class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> v(32);
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            v[int(log2(nums[i]))]++;
            sum+=nums[i];
        }
        if(sum<target) return -1;
        
        int i=0,res=0;
        while(i<30){
            if((1<<i)&target){
                if(v[i]>0) v[i]--;
                else{
                    while(i<30 && v[i]==0){
                        res++;
                        i++;
                    }
                    v[i]--;
                    continue;
                }
            }
            v[i+1]+=(v[i]/2);
            i++;
        }
        return res;
    }
};