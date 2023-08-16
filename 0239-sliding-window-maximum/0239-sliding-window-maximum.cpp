class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       priority_queue<pair<int,int>> p;
        p.push({nums[0],0});
        vector<int> ans;
        int temp=1;
        if(k==temp) ans.push_back(p.top().first);
        for(int i=1;i<nums.size();i++){
            
            while(p.size()>0 && p.top().second<(i-k+1)) p.pop();
            while(p.size()>0 && p.top().first<=nums[i]) p.pop();
            p.push({nums[i],i});
            temp++;
            if(temp>=k){
                ans.push_back(p.top().first);
            }
        }
        return ans;
    }
};