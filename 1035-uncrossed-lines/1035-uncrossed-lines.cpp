class Solution {
    vector<int> v;
    unordered_map<int,vector<int>> low;
    int fun(vector<int>& nums1,int ind,int high,vector<vector<int>>& dp){
        if(ind==nums1.size()){
            return 0;
        }
        int k=0,j=0;
        if(dp[ind][high]!=-1) return dp[ind][high];
        if(low[nums1[ind]].size()>0){
            v =low[nums1[ind]];
            k = lower_bound(v.begin(),v.end(),high) - v.begin();
           
            if(k<v.size()){
                j = 1+fun(nums1,ind+1,v[k]+1,dp);
            }
        }
        j = max(j,fun(nums1,ind+1,high,dp));
    return dp[ind][high] = j;
    }
    
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // first store index of every number in nums2.
        //now iterate through nums1, so it will have two option either take nearest index if present or just leave it and move forward.
        for(int i=0;i<nums2.size();i++){
            low[nums2[i]].push_back(i);
        }
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return fun(nums1,0,0,dp);
        
    }
};