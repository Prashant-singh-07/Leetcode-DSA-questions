class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int> m;
        for(auto k:s){
            m[k]++;
        }
        stack<char> st;
        
        int i=0;
        vector<int> vis(26,false);
        while(i<s.size()){
            if(vis[s[i]-'a']==false){
                while(st.size()>0 && m[st.top()]>=1 && st.top()>s[i]){
                    vis[st.top()-'a']=false;
                    st.pop(); 
                }
            
                st.push(s[i]);
                vis[s[i]-'a']=true;
                
            }
            m[s[i]]--;
            i++;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};