class Solution {
    private:
    int fun(vector<vector<int>>& pairs,int index,int end,vector<vector<int>>& dp){
        if(index==pairs.size()){
            return 0;
        }
        int k = end;
        if(end<0) k= 1000-end;
        if(dp[index][k]!=-1) return dp[index][k];
        int ans = 0;
        for(int i=index;i<pairs.size();i++){
            if(pairs[i][0]>end){
                ans = max(ans,1+fun(pairs,i+1,pairs[i][1],dp));
            }
        }
        return dp[index][k] = ans;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(n+1,vector<int>(2001,-1));
        int ans=0;
        for(int i=0;i<pairs.size();i++){
            ans = max(ans,1+fun(pairs,i+1,pairs[i][1],dp));
        }
        return ans;
    }
};