class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        stack<int> st;
        int n = obstacles.size();
        vector<int> ans(n,1);
       vector<int> v(n+1,INT_MAX);
        vector<int> indu(n+1,-1);
        for(int i=0;i<obstacles.size();i++){
            //equal or greater than to it.
            int ind = upper_bound(v.begin(),v.end(),obstacles[i]) - v.begin();
                
         
               ans[i]=ind+1;
                v[ind]=obstacles[i];
            
           
            
            
        }
        return ans;
    }
};