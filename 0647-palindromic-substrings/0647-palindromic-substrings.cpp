class Solution {
public:
    int countSubstrings(string s) {
      // for a palindrom substring of more than size 1, we should have first and last character equal, if(there is more than 1 element in first and last then check for string is palindrome or not).
        
        int n = s.size();
        vector<vector<int>> v(n,vector<int>(n+1));
       int count=0;
        for(int i=n-1;i>=0;i--){
            v[i][1]=true;
            count++;
            for(int j=i+1;j<n;j++){
                if(s[j]==s[i]){
                    if(j-i<=2){
                        v[i][j-i+1]=true;
                        count++;
                    }
                    else if(v[i+1][j-i-1]) v[i][j-i+1]=true,count++;
                }
            }
        }
        return count;
        
    }
};