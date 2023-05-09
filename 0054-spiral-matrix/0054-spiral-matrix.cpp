class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startr=0,startc=0;
        int m = matrix.size();
        int n = matrix[0].size();
        int endr = m-1;
        int endc = n-1;
        int i,j;
        vector<int> ans;
        while(startr<=endr && startc<=endc){
            //top column traversal
            i=startc;
            while(i<=endc){
                ans.push_back(matrix[startr][i]);
                i++;
            }
            //right row traversal by leaving top
            j = startr+1;
            while(j<=endr){
                ans.push_back(matrix[j][endc]);
                j++;
            }
            //down colum traversal
            j = endc-1;
            if(endr>startr){
            while(j>=startc){
                ans.push_back(matrix[endr][j]);
                j--;
            }
            }
            //left up row traversal
            i = endr-1;
            if(endc>startc){
            while(i>startr){
                ans.push_back(matrix[i][startc]);
                i--;
            }
            }
            startr++;
            startc++;
            endr--;
            endc--;
        }
        return ans;
    }
};