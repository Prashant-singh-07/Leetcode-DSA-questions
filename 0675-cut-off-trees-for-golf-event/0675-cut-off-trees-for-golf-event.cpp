class Solution {
public:
    
    int cutOffTree(vector<vector<int>>& forest) {
      // Lets Discuss algorthm about it.
      //     I have started analysing by fresh mind then ihave came to know that in any case i will always go from shortest to longest path blindly, there will be no if case in it.
      //         ALGO:-
      //             1) first find the node in sequence way using map data structure.
      //             2) iterate in all four direction.
      //             3) if map.size()==0 then stop and compare for shortest path.
       
        int row=forest.size();
        int col=forest[0].size();
         map<int,pair<int,int>> m;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(forest[i][j]>1) m[forest[i][j]] = {i,j};
            }
        }
       int ans=0,n;
        int srcr=0,srcc=0,destc,destr,flag,step=0;
        
        pair<int,int> p;
         for(auto k:m){
             destr=k.second.first;
             destc=k.second.second;
             queue<pair<int,int>> q;
             q.push({srcr,srcc});
              vector<vector<bool>> vis(row+1,vector<bool>(col+1,false));
             vis[srcr][srcc]=true;
             flag=0;
             step=0;
            
             //Write simple algorithm to reach from src to dest in min. step;
             while(!q.empty()){
                 n = q.size();
                 while(n>0){
                     p = q.front();
                     
                     if(p.first==destr && p.second==destc){
                         flag=1;
                             break;
                     }
                     q.pop();
                     if(p.first+1<row && forest[p.first +1][p.second]!=0 && vis[p.first+1][p.second]==false){
                         vis[p.first+1][p.second]=true;
                       q.push({p.first+1,p.second});
                     }
                     if(p.first-1>=0 && forest[p.first -1][p.second]!=0 && vis[p.first-1][p.second]==false){
                       q.push({p.first-1,p.second});
                         vis[p.first-1][p.second]=true;
                     }
                     if(p.second+1<col && forest[p.first][p.second+1]!=0 && vis[p.first][p.second+1]==false){
                       q.push({p.first,p.second+1});
                         vis[p.first][p.second+1]=true;
                     }
                     if(p.second-1>=0 && forest[p.first][p.second-1]!=0 && vis[p.first][p.second-1]==false){
                       q.push({p.first,p.second-1});
                         vis[p.first][p.second-1]=true;
                     }
                     n--;
                 }
                 if(flag==1) break;
                 step++;
             }
             
             if(flag==0) return -1;
             
             
             //vis.clear();
             ans+=step;
             
             
             srcc=destc;
             srcr=destr;
             //m.erase(k.first);
         }
        return ans;
    }
};