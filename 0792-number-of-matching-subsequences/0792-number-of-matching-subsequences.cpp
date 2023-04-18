class Solution {
public:
    unordered_map<char,vector<int>> m;
    int numMatchingSubseq(string s, vector<string>& words) {
        for(int i=0;i<s.size();i++){
            m[s[i]].push_back(i);
        }
        int prev=-1;
        vector<int> v;
        int flag=0,count=0;
        int upp;
        
        
        for(int i=0;i<words.size();i++){
            flag=0;
            prev=-1;
            for(int j=0;j<words[i].size();j++){
                if(m.find(words[i][j])==m.end()){
                    flag=1;
                    break;
                }
                v = m[words[i][j]];
                upp = upper_bound(v.begin(), v.end(), prev)-v.begin();
                //cout<<words[i][j]<<" "<<upper<<endl;
                
                if(upp>=v.size()){
                    cout<<words[i][j]<<upp;
                    flag=1;
                    break;
                }
                  prev=v[upp];
            }
            if(flag==0) count++;
        }
        return count;
    }
};