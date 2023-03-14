class Solution {
    private:
   unordered_map<string,int> m;
    bool check(string s){
         int left=0,right=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') left++;
            else if(s[i]==')'){
                if(left>0) left--;
                else{
               return false;
                }
            }
        }
        if(left>0) return false;
        return true;
    }
    
    
    void fun(string& s,string &temp,int count,int ind){
        if(ind==s.size()){
            if(count==0){
                if(check(temp)) m[temp]++;
            }
            return ;
        }
        temp+=s[ind];
        fun(s,temp,count,ind+1);
        temp.pop_back();
        fun(s,temp,count-1,ind+1);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        int left=0,right=0,count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') left++;
            else if(s[i]==')'){
                if(left>0) left--;
                else{
                count++;
                }
            }
        }
        if(left>0) count+=left;
        string temp="";
        fun(s,temp,count,0);
        vector<string> ans;
        for(auto k:m){
            ans.push_back(k.first);
        }
        return ans;
    }
};