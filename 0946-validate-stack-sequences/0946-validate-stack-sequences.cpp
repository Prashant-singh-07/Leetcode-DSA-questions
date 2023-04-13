class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j=0;
        stack<int> st;
        for(int i=0;i<popped.size();i++){
            if(st.empty() || st.top()!=popped[i]){
                while(j<pushed.size() && pushed[j]!=popped[i]) st.push(pushed[j]), j++;
                if(j==pushed.size()) return false;
                j++;
            }
            else{
                st.pop();
            }
        }
        return true;
    }
};