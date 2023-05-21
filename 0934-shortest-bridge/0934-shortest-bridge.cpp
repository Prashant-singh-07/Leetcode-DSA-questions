class Solution {
public:
// BFS method 
    void DFS(vector<vector<int>>& grid , int i , int j ,queue<pair<int,int>>&pending ,vector<vector<bool>>& visited )
    {
        if(i<0 ||i>=grid.size() ||j<0 ||j>=grid[0].size() ||grid[i][j]==0|| visited[i][j]== true )
        {
            return ;
        }
        pending.push({0,i*(grid[0].size())+j});
        visited[i][j]=true ;
        DFS(grid, i+1 , j , pending ,visited);
        DFS(grid, i-1 , j , pending , visited);
        DFS(grid, i , j+1 , pending , visited);
        DFS(grid, i , j-1 , pending ,visited);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size();
        vector<vector<bool>> visited(m ,vector<bool>(n,false));
        queue<pair<int,int>> pending ;
        bool is = true ;
        for(int i =0 ;i<m ;i++)
        {
            for( int j =0 ;j<n ;j++)
            {
                if(grid[i][j]==1)
                {
                    DFS(grid, i , j, pending, visited);
                    is= false;
                    break ;
                }
            }
            if(is== false)
            {
                break ;
            }
        }
        vector<pair<int,int>> dir= {{-1,0},{0,1},{0,-1},{1,0}};
        while(!pending.empty())
        {
            int dis = pending.front().first ;
            int i = pending.front().second/n;
            int j = pending.front().second%n;
           // cout<<dis<<" "<<i<<" "<<j<<endl;
            pending.pop();
            for( int k =0 ;k<dir.size() ;k++)
            {
                int nr = i+dir[k].first;
                int nc = j +dir[k].second;
                if(nr<0||nc<0||nr>=m||nc>=n||visited[nr][nc]==true)
                {
                    continue;
                }
                visited[nr][nc]=true ;
                if(grid[nr][nc]==1)
                {
                    return dis ;
                }
                pending.push({dis+1 ,nr*n+nc});
            }
        }
        return 0;
    }
};