class Solution {
public:
    vector<vector<string>> ans;
    bool check(string& temp){
        
        int l=0;
        int r=temp.size()-1;
        while(l<=r){
            if(temp[l]!=temp[r]) return false;
       l++;
            r--;
        }
        return true;
        
    }
    
    void fun(string& s,int ind,vector<string>& v){
        if(ind==s.size()){
            ans.push_back(v);
            return ;
        }
        string temp="";
        for(int i=0;i+ind<s.size();i++){
            temp=s.substr(ind,i+1);
            if(check(temp)){
                v.push_back(temp);
                fun(s,ind+i+1,v);
                v.pop_back();
            }
        }
        return ;
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> v;
        fun(s,0,v);
        return ans;
    }
};