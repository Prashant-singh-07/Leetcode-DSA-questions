class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> v(n);
        for(int i=0;i<roads.size();i++){
            v[roads[i][0]]++;
            v[roads[i][1]]++;
        }
        sort(v.begin(),v.end(),greater<int>());
        long long temp=n;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum += (v[i]*temp);
            temp--;
        }
        return sum;
    }
};