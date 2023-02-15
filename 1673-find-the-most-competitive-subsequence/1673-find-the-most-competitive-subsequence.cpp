class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
      stack<int> st;
        st.push(nums[0]);
        int n = nums.size();
        int s;
        for(int i=1;i<n;i++){
            s=st.size();
            while(s+(n-i-1)>=k && !st.empty() && st.top()>nums[i]){
                st.pop();
                s--;
            }
            if(s<k) st.push(nums[i]);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};