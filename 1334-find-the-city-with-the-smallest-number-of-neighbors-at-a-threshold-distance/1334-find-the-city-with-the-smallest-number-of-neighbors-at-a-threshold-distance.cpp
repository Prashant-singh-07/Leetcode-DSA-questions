class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
        unordered_map<int,vector<pair<int,int>>> m;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back({edges[i][1],edges[i][2]});
             m[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int ans=-1,count=INT_MAX,curr=0;
        pair<int,int> p;
        int point,wt;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            vector<int> vis(n,-1);
            curr=0;
            q.push({i,0});
            vis[i]=0;
            while(!q.empty()){
                p=q.front();
                q.pop();
                point=p.first;
                wt=p.second;
                if(wt>=dist || (vis[point]!=-1 && wt>vis[point])) continue;
                for(int i=0;i<m[point].size();i++){
                    if(vis[m[point][i].first]==-1){
                        if(wt+m[point][i].second<=dist){
                            vis[m[point][i].first]=wt+m[point][i].second;
                            q.push({m[point][i].first,vis[m[point][i].first]});
                            curr++;
                        }
                    }
                    else if(wt+m[point][i].second<=dist && vis[m[point][i].first]>wt+m[point][i].second){
                         vis[m[point][i].first]=wt+m[point][i].second;  
                         q.push({m[point][i].first,vis[m[point][i].first]});
                    }
                }
            }
            //cout<<i<<"  "<<curr<<endl;
            if(curr<=count){
                count=curr;
                ans=i;
            }
            vis.clear();
        }
        return ans;
    }
};