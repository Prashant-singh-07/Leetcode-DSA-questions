class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coord) {
        map<pair<int,int>,int> mp;
            
            for(auto a : coord){
                    
                    int x = a[0];
                    int y = a[1];
                    
                    if(x == m-1 && y == n-1) // If last cell
                       mp[{x-1,y-1}]++;
                    
                    else if(y == n-1){ // If last column
                        mp[{x,y-1}]++;
                        mp[{x-1,y-1}]++;
                    }
                    else if(x == m-1){ // If last row
                        mp[{x-1,y}]++;
                        mp[{x-1,y-1}]++;
                    }
                    else{  // Common cells
                            mp[{x-1,y}]++;
                            mp[{x,y-1}]++;
                            mp[{x-1,y-1}]++;
                            mp[{x,y}]++;
                    }
            }
            
            vector<long long> ans(5,0); // Answer array
            
            for(auto[a,b] : mp)
                    if(a.first >= 0 && a.second >= 0) // do not count out of the array row and column
                    ans[b]++;
            
            int sum = accumulate(ans.begin(),ans.end(),0); // total count of 1 , 2 , 3 , 4 in 2 * 2 block
            
             
            ans[0] = (long long)(m-1) * (long long)(n-1) - sum; // total 0 black block in matrix  - 1, 2, 3, 4 block
            return ans;
    }
};