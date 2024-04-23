class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
     vector<int> ans;
        if(n<=0) return ans;
        if(n==1){
            ans.push_back(0);
            return ans;
        }
        queue<int> q;
        vector<int> deg(n);
        vector<vector<int>> adj(n);
        
        for(int i=0;i<edges.size();i++){
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
            
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<n;i++){
            if(deg[i]==1){
                deg[i]--;
                q.push(i);
            }
        }
        int sz,curr;
        while(n>2){
           sz = q.size();
           n-=sz;
            while(sz>0){
                curr = q.front();
                q.pop();
                for(int i=0;i<adj[curr].size();i++){
                    deg[adj[curr][i]]--;
                    if(deg[adj[curr][i]] == 1) q.push(adj[curr][i]);
                }
                sz--;
            }
        }
        while(!q.empty()){
            curr = q.front();
            q.pop();
            ans.push_back(curr);
        }
        return ans;
    }
};