class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start=1,end= m*n;
        int row,col;
        int mid;
        while(start<=end){
            mid = start+((end-start)/2);
            row=mid/n;
            col= mid - (row*n);
           // col = col%n;
            if(col==0){
                row--;
                col=n-1;
            }
            else col--;
            //cout<<row<<"  "<<col<<endl;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) start=mid+1;
            else end=mid-1;
        }
        return false;
    }
};