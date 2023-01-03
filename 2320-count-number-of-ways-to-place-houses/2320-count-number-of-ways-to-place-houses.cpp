class Solution {
public:
    int countHousePlacements(int n) {
        int mod = 1000000007;
       //vector<vector<int>> v(n,vector<int>(2,0));
        vector<vector<pair<unsigned int,unsigned int>>> p(n,vector<pair<unsigned int,unsigned int>> (2,{0,0}));
        
        p[0][0] = {1,1};
        p[0][1] = {1,1};
        if(n==1){
            return 4;
        }
        for(int i=1;i<n;i++){
            /*v[i][0] = (v[i-1][0] +i)%mod;
            v[i][1] = (v[i-1][1]+i)%mod;*/
            p[i][0].first = p[i-1][0].second%mod;
            p[i][0].second = (p[i-1][0].first%mod+p[i-1][0].second%mod)%mod;
            
            p[i][1].first = p[i-1][1].second%mod;
            p[i][1].second = (p[i-1][1].first%mod+p[i-1][1].second%mod)%mod;
            
            
        }
        long long x = (p[n-1][0].first%mod+p[n-1][0].second%mod)%mod;
        long long y = (p[n-1][1].first%mod+p[n-1][1].second%mod)%mod;
        return (x*y)%mod;
    }
};