class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        queue<int> q;
       
        int m,node;
        vector<int> vis(n,-1);
        for(int j=0;j<n;j++){
        if(vis[j]==-1){
        vis[j]=0;
        q.push(j);
        while(q.size()>0){
           
            m = q.size();
            while(m>0){
                node = q.front();
                q.pop();
                for(int i=0;i<graph[node].size();i++){
                    if(vis[graph[node][i]]==-1){
                        q.push(graph[node][i]);
                        vis[graph[node][i]] = !(vis[node]);
                    }
                    else if(vis[node]==vis[graph[node][i]]) return false;
                }
                m--;
            }
        }
        }
        }
        return true;
    }
};