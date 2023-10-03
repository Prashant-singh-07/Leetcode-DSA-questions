class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        int ans=0,p;
        for(auto k:m){

            p=k.second;
                        cout<<p<<"  ";
            p--;
            ans+= ((p*p + p)/2);
            //ans--;
        }
        return ans;
    }
};