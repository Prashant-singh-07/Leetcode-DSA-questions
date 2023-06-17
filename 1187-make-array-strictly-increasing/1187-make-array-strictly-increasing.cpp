class Solution {
    // Here, we can create a 2d dp consisting of ind and previndex as row and column, so lets do it.
    
    int fun(vector<int>& arr1, vector<int>& arr2,int ind,vector<vector<int>>& dp,int prevIndex){
        if(ind==arr1.size()){
        return 0;
        }
        int ans=INT_MAX;
        int temp = arr1[ind];
        int prev;
        if(prevIndex==-1 && ind>0) prev=arr1[ind-1];
        if(prevIndex>-1) prev=arr2[prevIndex];
        int x;
        if(dp[ind][prevIndex+1]!=-1) return dp[ind][prevIndex+1];
        if(ind==0){
            ans = min(ans,fun(arr1,arr2,ind+1,dp,prevIndex));
            if(arr2[0]<temp){
            x = fun(arr1,arr2,ind+1,dp,0);
            if(x!=INT_MAX)
            ans = min(ans,1+x);
            }
        }
        else{
            if(temp>prev){
                   ans = min(ans,fun(arr1,arr2,ind+1,dp,-1)); 
            }
            int k = upper_bound(arr2.begin(),arr2.end(),prev) - arr2.begin();
            if(k<arr2.size()){
                 x=fun(arr1,arr2,ind+1,dp,k);
                if(x!=INT_MAX)
                ans = min(ans,1+x);
            }

        }
        return dp[ind][prevIndex+1] = ans;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        sort(arr2.begin(),arr2.end());
         int ans = fun(arr1,arr2,0,dp,-1);
         if(ans==INT_MAX) return -1;
         return ans;
    }
};