class Solution {
public:
    bool checkValidString(string s) {
       
        stack<int> st;
       deque<int> count;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*') count.push_back(i);
            else if(s[i]==')'){
                if(!st.empty()) st.pop();
                else if(!count.empty()) count.pop_front();
                else return false;
            }
            else{
                st.push(i);
            }
        }
        while(!st.empty()){
            if(!count.empty() && count.back()>st.top()) {
                count.pop_back();
                st.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
};