class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> prev,next;
        int n = arr.size();
        vector<int> prevv(n),nextv(n);
        for(int i = 0; i < arr.size(); i++) prevv[i] =  i + 1;
    for(int i = 0; i < arr.size(); i++) nextv[i] = arr.size() - i;
        for(int i=0;i<n;i++){
            while(!prev.empty() && arr[prev.top()]>arr[i]){
                prev.pop();
            }
            if(prev.empty()) prevv[i] = i+1;
            else prevv[i] = i-prev.top();
            prev.push(i);
            
             while(!next.empty() && arr[next.top()] > arr[i]){
       int h = next.top();
        next.pop();
        nextv[h] = i - h;
      }
        
      next.push(i);
        }
     int ans=0;
        int MOD= 1000000007;
        for(int i=0;i<n;i++){
            long long prod = (prevv[i]*nextv[i])%MOD;
            prod = (prod*arr[i])%MOD;
            ans = (ans + prod)%MOD;
            
        }
        return ans%MOD;
    }
};