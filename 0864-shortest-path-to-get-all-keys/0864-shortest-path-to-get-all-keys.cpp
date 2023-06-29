// class Solution {
//     int key=0;
//     int ans= INT_MAX;
//     void fun(vector<string>& grid,int row,int col,int curr,int mask,vector<vector<vector<int>>>& dp,int count){
//         int m = grid.size();
//         int n = grid[0].size();
//         int k,diff;
//         dp[row][col][mask]=count;
//         if(grid[row][col]>=65 && grid[row][col]<=90){
//                 diff = grid[row][col]-'A';
//             diff = 1<<diff;
//             if(!(mask&diff)){
//                return ;
//             }
//             }
//          else if(grid[row][col]>=97 && grid[row][col]<=122){
//              diff = grid[row][col]-'a';
//              diff = 1<<diff;
//              if(!(mask&diff)){
//                  curr++;
//              if(curr==key){
//                  ans = min(ans,count);
//                  return ;
//              }
//                   mask=mask|diff;
                 
//              }  
             
//          }
        
//         if(row+1<m && grid[row+1][col]!='#' && dp[row+1][col][mask]>count+1){
            
//          fun(grid,row+1,col,curr,mask,dp,count+1);
            
//         }
//          if(row-1>=0 && grid[row-1][col]!='#' && dp[row-1][col][mask]>count+1){
//              fun(grid,row-1,col,curr,mask,dp,count+1);
//         }
//          if(col+1<n && grid[row][col+1]!='#' && dp[row][col+1][mask]>count+1){
//            fun(grid,row,col+1,curr,mask,dp,count+1);  
//         }
//          if(col-1>=0 && grid[row][col-1]!='#' && dp[row][col-1][mask]>count+1){
//        fun(grid,row,col-1,curr,mask,dp,count+1);
            
//         }
//         return ;
//     }
// public:
//     int shortestPathAllKeys(vector<string>& grid) {
//         int count=0,row,col;
//         for(int i=0;i<grid.size();i++){
//             for(int j=0;j<grid[0].size();j++){
//                 if(grid[i][j]=='@'){
//                     row=i;
//                     col=j;
//                 }
//                 else if(grid[i][j]>=97 && grid[i][j]<=122){
//                     count++;
//                 }
//             }
//         }
//         key=count;
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>((1<<key), INT_MAX)));
//     fun(grid,row,col,0,0,dp,0);
//         if(ans==INT_MAX) return -1;
//         return ans;
//     }
// };

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid)
    {
        int m = grid.size() , n = grid[0].size() ;
        
        int r , c , k = 0 ;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='@')
                {
                    r = i , c = j ;
                }
                
				 // counting numbers of keys
                if(grid[i][j]>='a' && grid[i][j]<='z')
                    k++ ;
            }
        }
        
        int mask = (1<<k)-1 ;
        
        map<int,set<int>> vis ;
		// key = row*n + col ,  val is set of masks with which we have already visited the cell before.
        // ith bit in mask is 1 implies we donot have its key yet. 0 implies we have the key
        
        queue<pair<int,int>> q ; //row*n+col , mask
        
        q.push({r*n+c,mask}) ;
        vis[r*n+c].insert(mask) ;
        
        int dir[5] = {1,0,-1,0,1} ;
        
        int ans = 0 ;
        
        while(!q.empty())
        {
            int sz = q.size() ;
            
            while(sz--)
            {
                auto p = q.front() ; q.pop() ;
            
                int x = p.first/n , y = p.first%n ;
                mask = p.second ;
            
                if(grid[x][y]>='a' && grid[x][y]<='z')
                {
                    if(mask&(1<<(grid[x][y]-'a')))
                        mask-=(1<<(grid[x][y]-'a')) ;
                }
                
                // we got all the k keys
                if(mask==0)
                    return ans ;
                
                for(int i=0;i<4;i++)
                {
                    int newx = x+dir[i] , newy = y+dir[i+1] ;
                    
					// new cell going out of grid
                    if(newx<0 || newx>=m || newy<0 || newy>=n) 
                        continue ;
                    
                    if(grid[newx][newy]=='#') // new cell is a wall
                        continue ;
                    
					// new cell is lock and we don't have its key yet
                    if(grid[newx][newy]>='A' && grid[newx][newy]<='Z' && (mask&(1<<(grid[newx][newy]-'A'))) )
                    {
                        continue ;
                    }
                    
                    int key = (newx*n)+newy ;
                
				    // if the cell hasn't been visited with same set of keys
                    if(vis[key].find(mask)==vis[key].end()) 
                    {
                        q.push({key,mask}) ;
                        vis[key].insert(mask) ;
                    }
                }
            }
            
            ans++ ;
        }
        
        return -1 ;
        
    }
};