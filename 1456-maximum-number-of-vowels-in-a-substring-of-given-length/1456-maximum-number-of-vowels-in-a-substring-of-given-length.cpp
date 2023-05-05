class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
    int count=0;
        int ans=0;
        for(int i=0;i<k-1;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') count++;
        }
        for(int i=k-1;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            count++;
            
        }
            ans = max(ans,count);
        if(s[i-k+1]=='a' || s[i-k+1]=='e' || s[i-k+1]=='i' || s[i-k+1]=='o' || s[i-k+1]=='u') count--;
        
        }
        return ans;
    }
};