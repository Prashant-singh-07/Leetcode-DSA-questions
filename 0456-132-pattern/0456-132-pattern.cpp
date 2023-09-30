class Solution {
public:
    bool find132pattern(vector<int>& nums) {
//         stack<int> st;
//         st.push(nums[0]);
//         int high,temp;
//         for(int i=1;i<nums.size();i++){
//             if(st.top()<=nums[i]){
//                 st.push(nums[i]);
//             }
//             else{
//                 high=INT_MIN;
//                 //temp=INT_MAX;
//                 while(st.size()>0 && st.top()>=nums[i]){
//                     high=min(high,st.top());
//                     st.pop();
//                     if(st.size()>0 && st.top()<nums[i]) return true;
//                      //]if(st.size()>0 && st.top()<nums[i]) return true;
//                 }
//                 st.push(high);
//                 st.push(nums[i]);
                
//             }
//         }
//         return false;
        
        stack<pair<int,int>> st;
        vector<int> v(nums.size(),-1);
       
        st.push({nums[0],0});
        vector<int> mi(nums.size());
        mi[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            while(st.size()>0 && st.top().first <= nums[i]) st.pop();
            if(st.size()>0){
                v[i]=st.top().second;
            }
            st.push({nums[i],i});
            mi[i]=min(mi[i-1],nums[i]);
            if(v[i]>0){
                if(nums[i]>mi[v[i]-1]) return true;
            }
        }
        return false;
    }
};