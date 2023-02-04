class Solution {
public:
    bool checkInclusion(string str, string s2) {
       // int n = str.size();
       //  sort(str.begin(),str.end());
       //  string temp;
       //  for(int i=n-1;i<s2.size();i++){
       //      temp = s2.substr(i+1-n,n);
       //      sort(temp.begin(),temp.end());
       //      if(temp==str) return true;
       //  }
       //  return false;
        unordered_map<char,int> m,temp;
        for(int i=0;i<str.size();i++) m[str[i]]++;
        temp=m;
        int start=0;
        for(int i=0;i<s2.size();i++){
            if(m.find(s2[i])==m.end()){
               temp.clear();
                temp=m;
                start=i+1;
            }
            else{
                if(temp.find(s2[i])==temp.end()){
                    while(start<i && s2[start]!=s2[i]){
                        temp[s2[start]]++;
                            start++;
                    }
                    if(start<i && s2[start]==s2[i]) temp[s2[start]]++,start++;
                }
                
                temp[s2[i]]--;
                if(temp[s2[i]]==0) temp.erase(s2[i]);
                
                
            }
            if(temp.size()==0) return true;
        }
        return false;
    }
};