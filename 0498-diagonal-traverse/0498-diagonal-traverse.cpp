class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        int flag=0;
        int row=0,col=0;
        while(row!=m-1 || col!= n-1){
            if(flag==0){
                //it means it is increasing
                while(!(row<0 || row>=m || col<0 || col>=n)){
                    ans.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                row++;
                col--;
                if(col==n-1) row++;
                else col++;
                
                flag=1;
            }
            else{
                flag=0;
                while(!(row<0 || row>=m || col<0 || col>=n)){
                    ans.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                row--;
                col++;
                if(row==m-1) col++;
                else row++;
            }
        }
        ans.push_back(mat[m-1][n-1]);
        return ans;
    }
};