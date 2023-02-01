class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k==1 || k==n) return 0;
        vector<long long> candidates;
        for(int i=0;i<n-1;i++){
            candidates.push_back(weights[i]+weights[i+1]);
        }
        sort(candidates.begin(),candidates.end());
        long long int mi=0,ma=0;
        for(int i=0;i<k-1;i++){
            mi+=candidates[i];
            ma+=candidates[n-2-i];
        }
        
        return ma-mi;
    }
};