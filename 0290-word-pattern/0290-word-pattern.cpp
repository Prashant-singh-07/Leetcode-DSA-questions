class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        unordered_map<string,int> h;
        int k = pattern.size();
        int n = s.size();
        int j=0;
        string temp="";
        for(int i=0;i<n;i++){
            if(j==k) return false;
            if(s[i]!=' ') temp+=s[i];
            else{
                if(m.find(pattern[j])==m.end()){
                    //cout<<"yha tk to aa hi gya h"<<endl;
                    if(h.find(temp)==h.end()){
                        //cout<<"isme koi aaya"<<i<<endl;
                    m[pattern[j]]=temp;
                         h[temp]++;
                    temp="";
                    j++;
                       
                    }
                    else return false;
                }
                else{
                    if(m[pattern[j]]!=temp) return false;
                    temp="";
                    j++;
                }
            }
        }
        if(m.find(pattern[j])==m.end()){
            if(h[temp]==0){
                    m[pattern[j]]=temp;
                    temp="";
                    j++;
            }
            else return false;
                }
                else{
                    if(m[pattern[j]]!=temp) return false;
                    temp="";
                    j++;
                }
        
        if(j<k) return false;
        return true;
    }
};