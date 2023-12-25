class Solution {
public:
    int fun(string s,int ind,vector<int>& v){
        if(ind==s.size()) return 1;
        int ans=0;
        if(v[ind]!=-1) return v[ind];
        if(s[ind]!='0'){
            ans+=fun(s,ind+1,v);
            if(ind+1<s.size()){
                int temp = stoi(s.substr(ind,2));
                if(temp<=26){
                    ans+=fun(s,ind+2,v);
                }
            }
        }
        return v[ind] = ans;
    }
    int numDecodings(string s) {
        vector<int> v(s.size(),-1);
        return fun(s,0,v);
    }
};