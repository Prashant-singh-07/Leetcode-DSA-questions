class Trie {
public:
    class node{
        public:
        node* v[26];
        bool flag=false;
       
            
    };
    node* root = new node();
    Trie() {
        
    }
    
    void insert(string word) {
        node* temp = root;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(!(temp->v[c-'a']!=NULL)){
                node* naya = new node();
                temp->v[c-'a']=naya;
            }
            temp = temp->v[c-'a'];
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        node* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->v[word[i]-'a']==NULL) return false;
            temp=temp->v[word[i]-'a'];
        }
        return temp->flag;
    }
    
    bool startsWith(string word) {
        node* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->v[word[i]-'a']==NULL) return false;
            temp=temp->v[word[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */