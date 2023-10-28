class Solution {
   unordered_map<char,int> m;
    
    
    int mod = 1e9+7;
    int fun(int n,vector<vector<int>>& dp,int i,char ch){
        if(i==n) return 1;
        long long sum=0;
        if(dp[m[ch]][i]!=-1) return dp[m[ch]][i];
       if(ch=='a'){
           sum += fun(n,dp,i+1,'e');
       }
        else if(ch=='e'){
            sum+=fun(n,dp,i+1,'a');
            sum+=fun(n,dp,i+1,'i');
        }
        else if(ch=='i'){
            sum+=fun(n,dp,i+1,'e');
            sum+=fun(n,dp,i+1,'a');
            sum+=fun(n,dp,i+1,'o');
            sum+=fun(n,dp,i+1,'u');
        }
        else if(ch=='o'){
            sum+=fun(n,dp,i+1,'u');
            sum+=fun(n,dp,i+1,'i');
        }
        else if(ch=='u'){
            sum+=fun(n,dp,i+1,'a');
        }
        return dp[m[ch]][i] = sum%mod;
        
    }
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp (5,vector<int>(n,-1));
        m['a']=0;
    m['e']=1;
    m['i']=2;
    m['o']=3;
    m['u']=4;
        long long sum=0;
        int i=0;
         sum+=fun(n,dp,i+1,'e');
            sum+=fun(n,dp,i+1,'a');
            sum+=fun(n,dp,i+1,'o');
            sum+=fun(n,dp,i+1,'u');
        sum+=fun(n,dp,i+1,'i');
        return sum%mod;
    }
};