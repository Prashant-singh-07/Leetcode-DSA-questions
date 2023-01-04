class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(auto p:tasks) m[p]++;
        int ans=0,k;
        for(auto p:m){
          k = p.second;
        if(k==1) return -1;
        else if(k==2 || k==3) ans++;
            else{
                ans+=(k/3);
                if(k%3!=0) ans++;
            }
        }
        return ans;
    }
};