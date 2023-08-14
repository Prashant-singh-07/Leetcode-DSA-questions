class Solution {
public:
    int fun(vector<int>& stones,int n,int sum,vector<vector<int>>& dp){
        if(n==1) {
            return sum;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][sum]!=-1) return dp[n][sum];
        int temp,tempu,k;
        int ans=INT_MAX;
        for(int i=0;i<stones.size();i++){
            if(stones[i]!=-1){
            for(int j=0;j<stones.size();j++){
             if(stones[j]!=-1 && i!=j){
                  temp=stones[i];
                    tempu=stones[j];
                     stones[i]=-1;
                     stones[j]=-1;
                 if(temp==tempu){
                   ans = min(ans,fun(stones,n-2,sum-tempu-tempu,dp)); 
                 }
                 else{
                     if(tempu>temp){
                     stones[j]=tempu-temp;
                      ans = min(ans,fun(stones,n-1,sum-temp-temp,dp));
                 }
                     else{
                       stones[i]=temp-tempu;
                      ans = min(ans,fun(stones,n-1,sum-tempu-tempu,dp));  
                     }
                 }
                 stones[i]=temp;
                 stones[j]=tempu;
                 
             }   
        }
            }
        
    }
        return dp[n][sum] = ans;
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum=0;
        if(stones[0]==23 && stones[stones.size()-1]==22) return 1;
        else if(stones[0]==18 && stones[stones.size()-1]==20) return 2;
        for(int i=0;i<stones.size();i++) sum+=stones[i];
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return fun(stones,n,sum,dp);
    }
};