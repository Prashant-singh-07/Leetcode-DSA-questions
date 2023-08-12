class Solution {
    int n;
    int ans=INT_MAX;
    int fun(vector<int>& tasks,int time,int total,int session,int mask,vector<vector<vector<int>>>& dp){
        if(mask == (pow(2,n)-1)){
            ans=min(session,ans);
            return session;
        }
        int k=INT_MAX;
        if(dp[mask][total][session]!=-1) return dp[mask][total][session];
        for(int i=0;i<n;i++){
            if((mask>>i)%2==0){
                if(tasks[i]+total <= time){
                    k = min(k,fun(tasks,time,total+tasks[i],session,mask|(1<<i),dp));
                }
                else{
                   k = min(k, fun(tasks,time,tasks[i],session+1,mask|(1<<i),dp));
                }
            }
        }
        return dp[mask][total][session] = k;
    }
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
         n = tasks.size();
        int mask=0;
        vector<vector<vector<int>>> dp(1<<n,vector<vector<int>>(sessionTime+1,vector<int>(n+1,-1)));
        return fun(tasks,sessionTime,0,1,mask,dp);
        return ans;
    }
};