class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        string ans,temp;
        int len,flag,k;
        
        for(int i=0;i<s1.size();i++){
            len=i-0+1;
            if(len>s2.size()) break;
            if((s2.size())%len!=0 || (s1.size())%len!=0) continue;
            temp = s1.substr(0,len);
            flag=0;
            k=0;
            while(k<s1.size()){
                if(s1.substr(k,len) != temp) {
                    flag=1;
                    break;
                }
                k+=len;
            }
            if(flag==1) continue;
            k=0;
             while(k<s2.size()){
                if(s2.substr(k,len) != temp) {
                    flag=1;
                    break;
                }
                k+=len;
            }
            if(flag==0) ans=temp;
        }
        return ans;
    }
};