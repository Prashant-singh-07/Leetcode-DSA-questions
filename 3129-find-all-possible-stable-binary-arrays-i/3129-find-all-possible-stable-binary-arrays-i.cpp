/*
class Solution {
private:
    int LIM;
    int MOD = pow(10, 9) + 7;
    vector<vector<vector<vector<int>>>> dp;
public:
    int make(int zero, int one, int prev, int con){
        if(zero == 0 && one == 0)
            return 1;
        
        if(dp[zero][one][prev][con] != -1 && prev != -1)
            return dp[zero][one][prev][con];
        int ans = 0;
        if(zero > 0 && !(con == LIM && prev == 0)){
            if(prev == 0)
                ans += make(zero-1, one, 0, con+1);
            else
                ans += make(zero-1, one, 0, 1);
        }
        
        if(one  > 0 && !(con == LIM && prev == 1)){
            if(prev == 1)
                ans += make(zero, one-1, 1, con+1);
            else
                ans += make(zero, one-1, 1, 1);
        }
            
        if(prev != -1)
            return dp[zero][one][prev][con] = ans % MOD;
        
        return ans % MOD;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        LIM = limit;
        dp.resize(zero+1, vector<vector<vector<int>>> (one+1, vector<vector<int>> (2, vector<int> (limit+1, -1))));
        
        return make(zero, one, 0, 0);
    }
};
*/



class Solution {
public:
    int mod = 1e9 + 7;
    int fun(int zero,int one,int con,int prev,int limit,vector<vector<vector<vector<int>>>>& dp){
        if(zero==0 && one==0) return 1;
        if(dp[zero][one][prev][con]!=-1) return dp[zero][one][prev][con];
        int ans=0;
        if(zero>0 && !(con==limit && prev==0)){
            if(prev==0){
                ans+=fun(zero-1,one,con+1,0,limit,dp);
            }
            else{
                ans+=fun(zero-1,one,1,0,limit,dp);
            }
        }
        if(one>0 && !(con==limit && prev==1)){
            if(prev==1){
                ans+=fun(zero,one-1,con+1,1,limit,dp);
            }
            else{
                ans+=fun(zero,one-1,1,1,limit,dp);
            }
        }
        
        return dp[zero][one][prev][con] = ans%mod;
    }
    
    
    int numberOfStableArrays(int zero, int one, int limit) {
       vector<vector<vector<vector<int>>>> dp(zero+1, vector<vector<vector<int>>>(one+1,vector<vector<int>>(2,vector<int>(limit+1,-1))));
        return fun(zero,one,0,0,limit,dp);
    }
};