class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> v(26);
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                v[words[i][j]-'a']++;
            }
        }
        int n = words.size();
        for(int i=0;i<26;i++){
            if(v[i]%n!=0) return false;
        }
        return true;
    }
};