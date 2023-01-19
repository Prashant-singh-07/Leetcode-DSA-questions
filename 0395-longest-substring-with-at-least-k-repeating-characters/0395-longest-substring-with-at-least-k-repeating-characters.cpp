class Solution {
public:
    int longestSubstring(string s, int k) {
        //basically a string given,return longest substring where fequency of each char is greater than or equal to k.
       // can we do using n2 method
        //if(s.size()<2) return 0;
        unordered_map<char,int> m;
        int flag,ans=0;
        for(int i=0;i<s.size();i++){
           // m[s[i]]++;
            flag=0;
            for(int j=i;j<s.size();j++){
                m[s[j]]++;
                if(m[s[j]]==k) flag++;
                if(flag==m.size()) ans = max(ans,j-i+1); 
            }
            m.clear();
            flag=0;
        }
        return ans;
    }
};