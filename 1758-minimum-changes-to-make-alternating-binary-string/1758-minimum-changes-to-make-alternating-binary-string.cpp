class Solution {
public:
    int minOperations(string s) {
        char start='0';
        int count=0,ans=INT_MAX;
        for(int i=0;i<s.size();i++){
            if(s[i]!=start) count++;
            if(start=='0') start='1';
            else start='0';
        }
        ans = min(ans,count);
        start='1';
        count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=start) count++;
            if(start=='0') start='1';
            else start='0';
        }
        return min(ans,count);
    }
};