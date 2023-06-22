class Solution {
    private:
   
    int fun(vector<int>& price,int fee,int flag,int ind,vector<vector<int>>& dp){
        if(ind==price.size()) return 0;
        
       
        if(dp[ind][flag]!=-1) return dp[ind][flag];
        int buy=0,sell=0,pass=0;
        if(flag==0){
           buy = -price[ind]+fun(price,fee,1,ind+1,dp);
        }
        pass = fun(price,fee,flag,ind+1,dp);
        if(flag==1){
            sell = price[ind]-fee+fun(price,fee,0,ind+1,dp);
        }
        
        // else {
        //    if(price[ind] > start+fee){
        //     int p = price[ind]-start-fee;
        //     ans = p+fun(price,fee,-1,ind+1,dp);
        //    }
        //     else{
        //         ans = fun(price,fee,-1,ind+1,dp);
        //     }
        // }
        // ans = max(ans,fun(price,fee,startInd,ind+1,dp));
        return dp[ind][flag] = max(max(sell,buy),pass);
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return fun(prices,fee,0,0,dp);   
    }
};