class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        //direction change kha ho rhi h, isme to bs 
        int ans = INT_MIN;
        for(int i=0;i<left.size();i++){
            ans = max(ans,left[i]);
        }
        for(int i=0;i<right.size();i++){
            ans = max(ans,n-right[i]);
        }
        return ans;
    }
};