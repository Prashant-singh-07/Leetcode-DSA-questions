class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
     int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>> ans(m, vector<int>(n));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            unordered_set<int> set1;
            unordered_set<int> set2;
            
            int r = i - 1;
            int c = j - 1;
            while (r >= 0 && c >= 0) {
                set1.insert(grid[r--][c--]);
            }
            
            r = i + 1;
            c = j + 1;
            while (r < m && c < n) {
                set2.insert(grid[r++][c++]);
            }
            
            ans[i][j] = abs(static_cast<int>(set1.size() - set2.size()));
        }
    }
    
    return ans;
    }
};