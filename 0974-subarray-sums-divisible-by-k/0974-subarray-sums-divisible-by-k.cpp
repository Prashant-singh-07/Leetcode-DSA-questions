class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //u have to just find all those subarray whose sum will be multiple of k
        unordered_map<int,int> m;
        int s=0,ans=0,j;
        m[0]=1;
        for(auto p:nums){
            s+=p; 
            j = s%k;
            if(j<0) j+=k;
            if(m[j]>0) ans+=m[j];
            
            m[j]++;
        }
        return ans;
    }
};