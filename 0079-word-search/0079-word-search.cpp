class Solution {
public:
    bool fun(vector<vector<char>>& board,int r,int c,string& word,vector<vector<int>>& vis,int ind)
    {
        if(ind == word.size()) {
            // for(int i=0;i<board.size();i++){
            //     for(int j=0;j<board[0].size();j++){
            //         cout<<vis[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
            // cout<<endl;
            return true;
        }
        // if(r==1 && c==0){
        //     cout<<board[r][c]<<endl;
        //     cout<<word[ind]<<endl;
        // }
        if(r>=board.size() || r<0 || c>=board[0].size() || c<0 || ind>=word.size() || board[r][c]!=word[ind] || vis[r][c]==0) return false;
        
        vis[r][c]=0;
        bool res=false;
        res = res || fun(board,r+1,c,word,vis,ind+1);
        res = res || fun(board,r-1,c,word,vis,ind+1);
        res = res || fun(board,r,c+1,word,vis,ind+1);
        res = res || fun(board,r,c-1,word,vis,ind+1);
        vis[r][c]=-1;
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),-1));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
               if(fun(board,i,j,word,vis,0)) {
                  // cout<<i<<" "<<j<<endl;
                 return true;
               }
            }
        }
        return false;
    }
};