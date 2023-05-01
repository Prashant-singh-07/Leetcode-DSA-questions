class Solution {
public:
    double average(vector<int>& salary) {
        int mi = INT_MAX, ma = INT_MIN;
        long long sum=0;
        for(int i=0;i<salary.size();i++){
            mi = min(mi,salary[i]);
            ma = max(ma,salary[i]);
            sum+=salary[i];
        }
        sum-=ma;
        sum-=mi;
        int n = salary.size();
        n=n-2;
        double ans = double(sum) / n;
        return ans;
        
        
        
    }
};