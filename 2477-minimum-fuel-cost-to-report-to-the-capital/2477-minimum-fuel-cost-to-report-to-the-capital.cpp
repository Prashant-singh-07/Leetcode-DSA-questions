class Solution {
public:
    long long ans=0;
    unordered_map<int,vector<int>> m;
    int fun(int par,vector<bool>& vis,int seats){
        int res=0,count=0;
        for(int k:m[par]){
            if(vis[k]==false){
                vis[k]=true;
                res = 1+fun(k,vis,seats);
                count+=res;
                ans+=(res/seats);
             if(res%seats!=0) ans++;
            }
        }
        
        return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        for(int i=0;i<roads.size();i++){
            m[roads[i][0]].push_back(roads[i][1]);
            m[roads[i][1]].push_back(roads[i][0]);
        }
        int n = roads.size();
        vector<bool> vis(n+1,false);
        vis[0]=true;
        int k = fun(0,vis,seats);
        return ans;
    }
};