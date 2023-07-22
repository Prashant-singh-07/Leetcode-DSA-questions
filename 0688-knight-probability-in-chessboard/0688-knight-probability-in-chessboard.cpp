/*class Solution {
    private int[][]dir = new int[][]{{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    private double[][][] dp;
    public double knightProbability(int N, int K, int r, int c) {
        dp = new double[N][N][K + 1];
        return find(N,K,r,c);
    }
    public double find(int N,int K,int r,int c){
        if(r < 0 || r > N - 1 || c < 0 || c > N - 1) return 0;
        if(K == 0)  return 1;
        if(dp[r][c][K] != 0) return dp[r][c][K];
        double rate = 0;
        for(int i = 0;i < dir.length;i++)   rate += 0.125 * find(N,K - 1,r + dir[i][0],c + dir[i][1]);
        dp[r][c][K] = rate;
        return rate;
    }
}
*/


class Solution {
    
    private:
    double fun(int n,int k,int i,int j,vector<vector<vector<double>>>& dp,vector<vector<int>>& dir){
        if(i>=n || i<0 || j>=n || j<0) return 0;
        if(k==0) return 1;
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        double rate=0;
        for(int h=0;h<dir.size();h++){
            //cout<<dir[i][0]<<" "<<dir[i][1]<<" ";
           rate+= 0.125 * fun(n,k-1,i+dir[h][0],j+dir[h][1],dp,dir);
        }
        return dp[i][j][k]=rate;
        
        
        
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<int>> dir ={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
        vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(n+1, vector<double>(k+1,-1)));
      return fun(n,k,row,column,dp,dir);
        return dp[row][column][k];
    }
};