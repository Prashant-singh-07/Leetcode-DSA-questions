class Solution {
public:
    unordered_map<string,bool> m;
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        if(s1==s2) return true;
        if(s1.size()<=1) return false;
        int n = s1.size();
        if(m.find(s1+"*"+s2)!=m.end()) return  m[s1+"*"+s2];
        for(int i=0;i<n-1;i++){
            if(isScramble(s1.substr(0,i+1),s2.substr(n-i-1,i+1)) && isScramble(s1.substr(i+1,n-i-1),s2.substr(0,n-i-1))) return  m[s1+"*"+s2] = true;
             if(isScramble(s1.substr(0,i+1),s2.substr(0,i+1)) && isScramble(s1.substr(i+1,n-i),s2.substr(i+1,n-i))) return  m[s1+"*"+s2] = true;
        
        }
        return m[s1+"*"+s2] = false;
    }
};