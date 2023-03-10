class Solution {
public:
    int uniqueLetterString(string s) {
  unordered_map<char,vector<int>> m;
        int ans=1,temp,ind;
       int prev=1;
       m[s[0]].push_back(0);
    for(int i=1;i<s.size();i++){
        if(m.find(s[i])==m.end()){
            temp=prev+i+1;
            prev=temp;
            ans+=temp;
            m[s[i]].push_back(i);
        }
        else if(m[s[i]].size()==1){
            ind=m[s[i]][0];
            temp=i-ind-1;
            temp-=ind;
            
            temp+=prev;
            ans+=temp;
            prev=temp;
            m[s[i]].push_back(m[s[i]][0]);
            m[s[i]][0]=i;
        }
        else{
            ind=m[s[i]][0];
            temp=i-ind-1;
            
            temp-=(ind - m[s[i]][1]);
             temp++;
            temp+=prev;
            ans+=temp;
            prev=temp;
            m[s[i]][1]=m[s[i]][0];
            m[s[i]][0]=i;
        }
    }
        return ans;
    }
};