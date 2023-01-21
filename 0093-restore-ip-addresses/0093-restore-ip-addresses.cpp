class Solution {
public:
    vector<string> ans;
    void fun(string s,string curr,int ind,int flag){
        if(ind==s.size()){
            if(flag==4)
   curr.pop_back(),ans.push_back(curr), curr+=".";
            return ;
        }
        if(flag==4) return ;
        if(s[ind]=='0'){
        
           /* while(ind<s.size() && s[ind]=='0'){
                curr+=s[ind];
                curr+=".";
                fun(s,curr,ind+1,flag+1);
                curr.pop_back();
                ind++;
            }*/
            curr+=s[ind];
                curr+=".";
                fun(s,curr,ind+1,flag+1);
                curr.pop_back();
        }
        else{
            int k = s[ind]-'0';
            while(ind<s.size() && k<=255){
                curr+=s[ind];
                curr+=".";
                fun(s,curr,ind+1,flag+1);
                curr.pop_back();
                k=k*10;
                if(ind+1<s.size())
                k=k+(s[ind+1]-'0');
                ind++;
            }
        }
        return ;
    }
    vector<string> restoreIpAddresses(string s) {
        string curr="";
        fun(s,curr,0,0);
        return ans;
        
        
    }
};