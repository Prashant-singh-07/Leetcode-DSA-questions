class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        for(int i=n-1;i<haystack.size();i++){
            if(haystack.substr(i-n+1,n)==needle) return i-n+1;
        }
        return -1;
    }
};