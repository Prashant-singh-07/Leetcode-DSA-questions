class Solution {
public:
    char findTheDifference(string s, string t) {
		// for(int i=0;i<s.size();i++)
		// t[i+1]+=t[i]-s[i]; //Passing the diff: (t[i]-s[i]) to t[i+1]
		// return t[t.size()-1]; 
         vector<int> a(26,0);
        vector<int> b(26,0);
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        b[t[t.size()-1]-'a']++;
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) return 'a'+i;
        }
        return 'a';
    }
};