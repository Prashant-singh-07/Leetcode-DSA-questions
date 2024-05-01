class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                string temp = word.substr(0,i+1);
                reverse(temp.begin(),temp.end());
                string temp1 = word.substr(i+1,n-i-1);
                return temp+temp1;
            }
        }
        return word;
    }
};