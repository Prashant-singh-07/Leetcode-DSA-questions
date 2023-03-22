class Solution {
    private:
      void dfs(vector<vector<pair<int,int>>>& v,vector<bool>& vis,int root){
          if(vis[root]) return ;
          vis[root]=true;
          pair<int,int> p;
          for(int i=0;i<v[root].size();i++){
              p = v[root][i];
              ans = min(ans,p.second);
              if(!vis[p.first])
              dfs(v,vis,p.first);
          }
      }
public:
    int ans=INT_MAX;
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> v(n+1);
        for(int i=0;i<roads.size();i++){
            v[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            v[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<bool> visited(n+1,false);
        dfs(v,visited,1);
        return ans;
    }
};