class Solution {
    private:
    int ans=0;
    int fun(vector<vector<int>>& adj,string& s,int ind,vector<int>& dp){
        
        //if(dp[ind]!=-1) return dp[ind];
        if(adj[ind].size()==0) return 1;
        int p,left=0,temp=-1;
        for(int i=0;i<adj[ind].size();i++){
            if(s[ind]==s[adj[ind][i]]){
               // if(dp[adj[ind][i]]==-1)
                p=fun(adj,s,adj[ind][i],dp);
            }
            else{
                //if(dp[adj[ind][i]]!=-1) p = dp[adj[ind][i]];
                 p = fun(adj,s,adj[ind][i],dp);
                if(p>=left){
                    temp=left;
                    left=p;
                }
                else{
                    if(p>temp) temp=p;
                }
            }
        }
        //if(temp!=-1)
        ans = max(ans,left+temp+1);
        ans = max(left+1,ans);
        return left+1;
        
        
        
        
    }
public:
    int longestPath(vector<int>& parent, string s) {
        unordered_map<int,int> m;
        if(parent.size()==1 && s.size()==1) return 1;
        int n = parent.size();
        vector<int> dp(n+1,-1);
        vector<vector<int>> adj(n+1);
        for(int i=1;i<parent.size();i++){
            adj[parent[i]].push_back(i);
        }
        int k = fun(adj,s,0,dp);
        return ans;
    }
};