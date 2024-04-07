class Solution {
public:
    string getSmallestString(string s, int k) {
        string temp="";
        int m1,m2;
        for(int i=0;i<s.size();i++){
            // if(s[i]!='a' && k>0){
                m1 = s[i]-'a';
                m2 = ('z'-s[i]);
                m2++;
                m1 = min(m1,m2);
                if(m1<=k){
                k-=m1;
                temp+="a";
                }
                else{
                    temp+=(s[i]-k);
                    k=0;
                }
            // }
            // else temp+=s[i];
        }
        return temp;
    }
};