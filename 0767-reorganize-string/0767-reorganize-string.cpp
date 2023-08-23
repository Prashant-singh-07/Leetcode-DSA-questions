class Solution {
public:
    string reorganizeString(string s) {
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++) v[s[i]-'a']++;
        string ans="";
        int low,ind;
        int prev=27;
        for(int i=0;i<s.size();i++){
            low=0;
            for(int j=0;j<26;j++){
                if(j!=prev && v[j]>low){
                    low=v[j];
                    ind=j;
                }
            }
            if(low==0) return "";
            v[ind]--;
            ans+=('a'+ind);
            prev=ind;
            //cout<<prev<<endl;
        }
        return ans;
    }
};