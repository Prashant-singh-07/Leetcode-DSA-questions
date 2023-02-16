class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans=INT_MIN;
        int s;
        long long sum=0;
      vector<vector<int>> v(m,vector<int>(n));
        for(int i=0;i<m;i++){
            v[i][0]=matrix[i][0];
            for(int j=1;j<n;j++){
                v[i][j] = v[i][j-1]+matrix[i][j];
                }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int p=0;p<=j;p++){
                    sum=0;
                    for(int r=i;r<m;r++){
                        if(p>0) s = v[r][j]-v[r][p-1];
                        else s = v[r][j];
                        sum+=s;
                        if(sum<=k){
                            if(sum>ans) ans=sum;
                            
                        }                 
                            
                    }
                }
            }
        }
        return ans;
    }
};