class Solution {
    private:
    int mod=1e9+7;
    int fun(int count,int low, int high, int zero, int one,vector<int>& dp){
        if(count>high) return 0;
        if(count==high) return 1;
        if(dp[count]!=-1) return dp[count];
        long long res=0;
        if(count>=low && count<=high) res++;
        res+=fun(count+zero,low,high,zero,one,dp);
        res+=fun(count+one,low,high,zero,one,dp);
        res=res%mod;
        return dp[count] = res;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return fun(0,low,high,zero,one,dp);
    }
};