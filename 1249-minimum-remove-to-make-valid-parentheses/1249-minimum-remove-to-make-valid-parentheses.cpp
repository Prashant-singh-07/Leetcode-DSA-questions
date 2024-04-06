class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(st.size()==0) s[i]='1';
                else st.pop();
            }
        }
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='1'){
                if(st.size()>0 && i==st.top()) {
                    st.pop();
                    continue;
                }
                ans+=s[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};