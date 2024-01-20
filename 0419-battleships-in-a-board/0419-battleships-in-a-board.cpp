class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n = board[0].size();
        int ans=0,k;
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if(board[i][j]=='X'){
                  ans++;
                  board[i][j]='p';
                  if(i+1<m && board[i+1][j]=='X') {
                      k = i+1;
                      while(k<m && board[k][j]=='X'){
                          board[k][j]='p';
                          k++;
                      } 
                  }
                  else if(j+1<n && board[i][j+1]=='X'){
                      k=j+1;
                      while(k<n && board[i][k]=='X'){
                           board[i][k]='p';
                          k++;
                      }
                  }
              }
          }
          // cout<<board[0][0];
          // cout<<board[0][3];
          // cout<<board[1][3];
          // cout<<board[2][3];
          // cout<<endl;
      }
        return ans;
    }
};