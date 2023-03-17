class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n,INT_MAX);
        s.push(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i]) s.pop();
            if(!s.empty()) ans[i]=s.top();
            s.push(nums[i]);
        }
        int i=n-1,j=0;
      while(j<i){
          if(ans[i]==INT_MAX){
              while(j<i && nums[j]<=nums[i]){
                  j++;
              }
              if(j<i){
                  ans[i]=nums[j];
                  
              }
          }
          i--;
      }
        for(int i=0;i<ans.size();i++) if(ans[i]==INT_MAX) ans[i]=-1;
       return ans;
    }
};