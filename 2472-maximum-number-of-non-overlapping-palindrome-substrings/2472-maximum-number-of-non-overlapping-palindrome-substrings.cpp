class Solution {
public:
    int maxPalindromes(string s, int k) {
        // firstly i will create all possible substring and check whether it is Palindrome or not.
        int n = s.size();
        if(k==1) return n;
        int flag=0,low,high;
        vector<int> v(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i+k-1;j<n;j++){
                low=i;
                high=j;
                flag=0;
              while(low<=high){
                  if(s[low]!=s[high]){
                      flag=1;
                      break;
                  }
                  low++;
                  high--;
              }
                if(flag==0)
                  v[j] = i;
            }
        }
        vector<int> dp(n);
        if(v[0]!=-1) dp[0]=1;
        else dp[0]=0;
        
        for(int i=1;i<n;i++){
        //cout<<v[i]<<" ";
            if(v[i]==-1) dp[i]=dp[i-1];
            else{
                if(v[i]==0) dp[i]=max(1,dp[i-1]);
                else dp[i]=max(dp[i-1],1+dp[v[i]-1]);
            }
            
        }
        return dp[n-1];
    }
};