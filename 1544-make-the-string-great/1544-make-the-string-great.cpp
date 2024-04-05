class Solution {
public:
    string makeGood(string s) {
        string ans="";
        int i;
        while(ans.size()==0){
        for(i=0;i<s.size()-1;i++){
            if((s[i]-'a')==(s[i+1]-'A') || (s[i]-'A')==(s[i+1]-'a')){
                i++;
            }
            else ans+=s[i];
        }
        if(i==s.size()-1) ans+=s[i];
            if(ans=="") return ans;
        for(i=0;i<ans.size()-1;i++){
            if((ans[i]-'a')==(ans[i+1]-'A') || (ans[i]-'A')==(ans[i+1]-'a')){
                s=ans;
                ans="";
                break;
            }
        }
    }
        return ans;
    }
};