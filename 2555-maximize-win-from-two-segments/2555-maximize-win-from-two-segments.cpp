class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int ans=0,start=0;
        int j,l;
        vector<int> dp(prizePositions.size());
         for(int i=0;i<prizePositions.size();i++){
             while(prizePositions[i] - prizePositions[start]>k) start++;
             if(start==0) l=0;
             else l=dp[start-1];
             j = i-start+1;
             ans=max(ans,j+l);
             //now updation of dp;
             if(i>0) l=dp[i-1];
             else l=0;
             dp[i] = max(j,l);
         }
        return ans;
    }
};