class WordDictionary {
public:
    class node{
        public:
        node* v[26];
        bool flag=false;
    };
    node* root = new node();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        node* temp=root;
        for(int i=0;i<word.size();i++){
            if(!(temp->v[word[i]-'a']!=NULL)){
                node* nay = new node();
                temp->v[word[i]-'a'] = nay;
            }
            temp = temp->v[word[i]-'a'];
        }
        temp->flag=true;
    }
    bool fun(int ind,string word,node* aaya){
        if(ind==word.size()) return aaya->flag;
        node* temp = aaya;
        for(int i=ind;i<word.size();i++){
            if(word[i]!='.'  && !(temp->v[word[i]-'a']!=NULL)) return false;
            else if(word[i]=='.'){
                /*if(i+1==word.size()){
                    cout<<"yha p chla h ye "<<i<<"  "<<word[i];
                 return true;
                }*/
                bool ans = false;
                //node* k[26] = temp->v;
                for(int j=0;j<26;j++){
                    if(temp->v[j]!=NULL){
                       ans =fun(i+1,word,temp->v[j]); 
                        if(ans) return true;
                    }
                }
                return ans;
            }
            else{
                temp = temp->v[word[i]-'a'];
            }
        }
        return temp->flag;
    }
    bool search(string word) {
        node* temp=root;
        return fun(0,word,temp);
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */