class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
     vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> vis(n);
        priority_queue<pair<double,int>> p;
        p.push({1.00,start});
        vis[start]=true;
        pair<double,int> temp;
        int curr;
        while(!p.empty()){
            temp = p.top();
            p.pop();
            if(temp.second==end) return temp.first;
            curr = temp.second;
            
            for(int i=0;i<adj[curr].size();i++){
                if(adj[curr][i].second * temp.first > vis[adj[curr][i].first]){
                    vis[adj[curr][i].first]=adj[curr][i].second * temp.first;
            p.push({vis[adj[curr][i].first],adj[curr][i].first});                  
                }
            }
            
        }
    return 0;
    }
};