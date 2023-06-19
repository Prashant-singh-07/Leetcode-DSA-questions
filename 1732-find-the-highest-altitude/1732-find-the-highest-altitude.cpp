class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int start=0;
        for(int i=0;i<gain.size();i++){
            start+=gain[i];
            ans=max(ans,start);
        }
        return ans;
    }
};