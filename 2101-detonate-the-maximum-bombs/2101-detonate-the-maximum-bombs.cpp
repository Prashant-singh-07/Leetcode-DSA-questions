class Solution {
public:
    int dfs(vector<bool>& vis,vector<vector<int>>& v,int ind){
        int k=1;
        vis[ind]=true;
       // if(v[ind].size()==0) return 1;
        for(int i=0;i<v[ind].size();i++){
            if(vis[v[ind][i]]==false){
                k+=dfs(vis,v,v[ind][i]);
            }
        }
       
        return k;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        // //1st problem: How to identify that a circle will be till which limit, so i have seen one ver important formula:-
        // if(diff(x1-x2)*diff(x1-x2) + diff(y1-y2)*diff(y1-y2)<=r1*r1) then it means that x2,y2 circle is in range of circle r1;
        int n = bombs.size();
        vector<vector<int>> v(n);
        for(int i=0;i<bombs.size();i++){
            long long r1;
            
            r1 = bombs[i][2];
            for(int j=0;j<bombs.size();j++){
                if(i!=j){
                    long long x2,y2;
                    x2=abs(bombs[i][0]-bombs[j][0]);
                    y2 = abs(bombs[i][1]-bombs[j][1]);
                    if((x2*x2)+(y2*y2)<=(r1*r1)){
                        v[i].push_back(j);
                    }
                }
            }
            
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            ans = max(ans,dfs(vis,v,i));
        }
        return ans;
        
        
    }
};