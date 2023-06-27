class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
     priority_queue<pair<long long,pair<int,int>>> p;
        vector<int> temp;
       temp=nums1;
        long long sum;
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<nums2.size();j++){
                sum=temp[i]+nums2[j];
                if(p.size()<k) p.push({sum,{temp[i],nums2[j]}});
                else{
                    if(p.top().first<=sum){
                        break;
                    }
                    else{
                        p.pop();
                        p.push({sum,{temp[i],nums2[j]}});
                    }
                }
            }
        }
        vector<vector<int>> ans;
        while(p.size()>0){
            ans.push_back({p.top().second.first,p.top().second.second});
            p.pop();
        }
        return ans;
    }
};