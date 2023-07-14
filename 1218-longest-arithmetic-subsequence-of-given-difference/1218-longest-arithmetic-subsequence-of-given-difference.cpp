class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> m;
        int n = arr.size();
        vector<int> dp(n,1);
        int ans=1;
        
        for(int i=0;i<n;i++){
            if(m.find(arr[i]-difference)!=m.end()){
                dp[i]+=dp[m[arr[i]-difference]];
                ans=max(ans,dp[i]);
            }
            m[arr[i]]=i;
            
        }
        return ans;
    }
};