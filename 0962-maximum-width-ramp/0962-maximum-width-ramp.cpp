class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans=0,diff;
        stack<pair<int,int>> s,temp;
        s.push({nums[0],0});
        for(int i=1;i<nums.size();i++){
            if(s.top().first<=nums[i]){
            while(!s.empty() && s.top().first<=nums[i]){
            temp.push(s.top());
            diff = i - s.top().second;
            ans = max(diff,ans);
            s.pop();
        }
           
            while(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
            }
            else{
                s.push({nums[i],i});
            }
        
            
        }
        return ans;
    }
};