class Solution {
    private:
    long long fun(int count,vector<vector<int>>& v,int ind,vector<bool>& vis){
        vis[ind]=true;
        long long m=0;
        for(int i=0;i<v[ind].size();i++){
            if(vis[v[ind][i]]!=true){
                m+=fun(count,v,v[ind][i],vis);
            }
        }
        return m+1;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,false);
        long long ans =0,p;
        long long sum=0,k;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                k = fun(0,v,i,vis);
                p=k*sum;
                ans+=p;
                sum+=k;
            }
        }
        return ans;
    }
};