class Solution {
     unordered_map<char,vector<char>> m;
    vector<string> ans;
    void fun(string& s,int i,string temp){
        if(i==s.size()){
            if(temp!="")
            ans.push_back(temp);
            return ;
        }
        for(int j=0;j<m[s[i]].size();j++){
           fun(s,i+1,temp+m[s[i]][j]);
        }
        return ;
    }
public:
    vector<string> letterCombinations(string digits) {
       m['2']={'a','b','c'};
        m['3']={'d','e','f'};
        m['4']={'g','h','i'};
        m['5']={'j','k','l'};
        m['6']={'m','n','o'};
        m['7']={'p','q','r','s'};
        m['8']={'t','u','v'};
        m['9']={'w','x','y','z'};
        string temp="";
        fun(digits,0,temp);
        return ans;
    }
};