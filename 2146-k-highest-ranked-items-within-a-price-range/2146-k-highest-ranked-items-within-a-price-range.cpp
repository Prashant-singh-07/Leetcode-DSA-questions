class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
//         GIVEN:- 
//      a grid of m*n size given.
//         0: can't pass
//         1: can pass
//         >1:can pass with secific price of item
            
//     here START is given so we have to start from that position.
//          PRICE is given which shows range of pricing of any object inclusive.
            
//      PROBLEM STATEMENT:-
//          find k highest rank objcts.
//          how to spcify rank:-
//              shorter distance.
//              lower price.
//              lower row no.
//              lower col no.+
        pair<pair<int,int>,pair<int,int>> p = {{1,1},{1,1}};
       // p.push({{1,1},1,1});
        pair<int,int> j;
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        int count=0,step=0,si,row,col;
        priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>> > pq;
        int maxr=grid.size();
        int maxc = grid[0].size();
        vector<vector<int>> vis(maxr,vector<int>(maxc,-1));
        vis[start[0]][start[1]]++;
        while(pq.size()<k && q.size()>0){
            si = q.size();
            while(si>0){
                j = q.front();
                q.pop();
                row=j.first;
                col=j.second;
                if(grid[row][col]>=pricing[0] && grid[row][col]<=pricing[1]) pq.push({{step,grid[row][col]},{row,col}});
                if(row+1<maxr && vis[row+1][col]==-1 && grid[row+1][col]!=0){
                    vis[row+1][col]++;
                    q.push({row+1,col});
                }
                if(col+1<maxc && vis[row][col+1]==-1 && grid[row][col+1]!=0){
                    vis[row][col+1]++;
                    q.push({row,col+1});
                }
                if(row-1>=0 && vis[row-1][col]==-1 && grid[row-1][col]!=0){
                    vis[row-1][col]++;
                    q.push({row-1,col});
                }
                if(col-1>=0 && vis[row][col-1]==-1 && grid[row][col-1]!=0){
                    vis[row][col-1]++;
                    q.push({row,col-1});
                }
                si--;
            }
            step++;
        }
         int i=0;
        vector<vector<int>> ans;
        while(i<k && pq.size()>0){
            pair<pair<int,int>,pair<int,int>> l = pq.top();
            pq.pop();
            ans.push_back({l.second.first,l.second.second});
            i++;
        }
       
        
        
        return ans;
    }
};