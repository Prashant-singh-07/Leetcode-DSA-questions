class Solution {
public:
    bool checkInclusion(string str, string s2) {
       int n = str.size();
        sort(str.begin(),str.end());
        string temp;
        for(int i=n-1;i<s2.size();i++){
            temp = s2.substr(i+1-n,n);
            sort(temp.begin(),temp.end());
            if(temp==str) return true;
        }
        return false;
    }
};