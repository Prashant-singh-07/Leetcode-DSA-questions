class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        unordered_map<int,int> m;
        priority_queue<int> low;
        priority_queue<int,vector<int>,greater<int>> high;
        int i=0;
            while(i<k){
                low.push(nums[i++]);
            }
        for(int j=0;j<(k/2);j++){
            high.push(low.top());
            low.pop();
        }
        
        while(true){
            ans.push_back((k&1)?low.top():((double)low.top()+(double)high.top())*0.5);
            if(i>=nums.size()) break;
            
            int outNum=nums[i-k];
            int inNum=nums[i++];
            int balance=0;
            
            balance += outNum<=low.top()?-1:1;
            m[outNum]++;
            
            if(!low.empty() && inNum<=low.top()){
                balance++;
                low.push(inNum);
            }
            else {
                balance--;
                high.push(inNum);
            }
            
            if(balance<0){
                low.push(high.top());
                high.pop();
                balance++;
            }
            if(balance>0){
                high.push(low.top());
                low.pop();
                balance--;
            }
            
            while(m[low.top()]){
                    m[low.top()]--;
                    low.pop();
                }

                while(!high.empty() && m[high.top()]){
                    m[high.top()]--;
                    high.pop();
                }
            
            
        }
        return ans;
    }
};