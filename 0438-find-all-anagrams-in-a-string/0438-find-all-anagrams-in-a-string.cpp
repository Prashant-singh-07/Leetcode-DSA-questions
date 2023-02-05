class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> m;
        for(int i=0;i<p.size();i++){
            m[p[i]]++;
        }
        unordered_map<char,int> temp;
        temp=m;
        vector<int> ans;
        int start=0;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
                temp.clear();
                temp=m;
                start=i+1;
            }
            else{
                while(start<i && temp.find(s[i])==temp.end()){
                    temp[s[start]]++;
                    start++;
                }
                temp[s[i]]--;
                if(temp[s[i]]==0){
                    temp.erase(s[i]);
                    if(temp.size()==0) ans.push_back(start);
                }
            }
        }
        return ans;
    }
};