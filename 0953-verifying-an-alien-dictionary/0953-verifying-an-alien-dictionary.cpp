class Solution {
public:
    bool isAlienSorted(vector<string>& word, string order) {
        unordered_map<char,int> m;
        for(int i=0;i<order.size();i++){
            m[order[i]]=i;
        }
        string temp,tempu;
        int j,k;
        for(int i=1;i<word.size();i++){
            temp=word[i-1];
            tempu=word[i];
            j=0,k=0;
            while(j<temp.size() && k<tempu.size() && m[temp[j]]==m[tempu[k]]){
                j++;
                k++;
            }
            if(j==temp.size() && k==tempu.size()) continue;
            else if(k==tempu.size()) return false;
            else if(j==temp.size()) continue;
            else if(m[temp[j]]>m[tempu[k]]) return false;
        }
        return true;
    }
};