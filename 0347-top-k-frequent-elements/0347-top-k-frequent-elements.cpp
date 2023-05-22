class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        for(auto j:m){
            p.push({j.second,j.first});
            if(p.size()>k){
                p.pop();
            }
        }
        vector<int> ans;
        pair<int,int> temp;
        while(!p.empty()){
            temp = p.top();
            p.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
};