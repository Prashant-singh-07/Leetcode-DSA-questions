class Solution {
public:
   bool check(string s){
        int l=0;
       int r=s.size()-1;
       while(l<r){
           if(s[l]!=s[r]) return false;
           l++;
           r--;
       }
        return true;
    }
    
    int countSubstrings(string s) {
        int ans=0;
        int n = s.size();
        vector<int> dp(n+1);
        
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                if(check(s.substr(j,i-j+1))) ans++;
            }
        }
        return ans;
    }
};