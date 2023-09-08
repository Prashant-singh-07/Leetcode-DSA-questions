class Solution {
public:
    vector<vector<int>> generate(int n) {
        int i,j;
        vector<vector<int>> a(n);
        for(i=0;i<n;i++){
            vector<int> v(i+1);
           v[0] = 1;
            //v[i] = 1;
            j = 1;
            while(j<i){
                v[j] = a[i-1][j-1] + a[i-1][j];
                j++;
            }
            v[i] = 1;
            a[i] = v;
        }
        return a;
    }
};