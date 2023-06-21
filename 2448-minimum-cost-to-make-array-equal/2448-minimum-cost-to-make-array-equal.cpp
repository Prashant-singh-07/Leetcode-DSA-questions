class Solution {
   long long fun(vector<pair<int,int>>& v,int mid){
       long long ans=0;
       long long diff;
       for(int i=0;i<v.size();i++){
           diff = abs(v[i].first - mid);
           ans+= (diff*v[i].second);
       }
       return ans;
   }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        int n = nums.size();
       long long ans=0,total=0,median=0,wa=0;
        for(int i=0;i<v.size();i++){
            wa+=v[i].second;
        }
        int i=0;
        while(total < (wa+1)/2 && i<nums.size()){
            total+=v[i].second;
            median=v[i].first;
            i++;
        }
        for(int i=0;i<cost.size();i++){
            ans += (abs(nums[i]-median))*cost[i];
        }
        return ans;
    }
};