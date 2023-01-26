class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> m;
        for(int i=0;i<flights.size();i++){
            m[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> vis(n+1,INT_MAX);
        queue<pair<int,int>> q;
        q.push({src,0});
        int count=0;
        int suzu;
        pair<int,int> p;
        int ans=INT_MAX;
        while(!q.empty() && count<=k){
        suzu=q.size();
            while(suzu>0){
                p = q.front();
                q.pop();
                if(m[p.first].size()>0){
                for(auto j:m[p.first]){
                 if(j.first==dst) ans = min(ans,j.second+p.second);
                    if(j.second+p.second<vis[j.first]){
                        q.push({j.first,j.second+p.second});
                        vis[j.first]=j.second+p.second;
                    }        
                }
                }
                
                suzu--;
            }
            count++;
        }
        //ans=vis[dst];
        if(ans==INT_MAX) return -1;
        return ans;
    }
};