class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag=false;
        int c=0;
        if(word[0]>=65 && word[0]<=90) c++,flag=true;
        int p;
        for(int i=1;i<word.size();i++){
            p=word[i];
            if(p>=65 && p<=90 && !flag) return false;
            if(p>=65 && p<=90) c++;
            
        }
        if(c>1 && c<word.size()) return false;
        return true;
    }
};