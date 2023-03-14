class MagicDictionary {
public:
    class trie{
        public:
        trie* v[27];
        bool end=false;
       
    };
    
    trie* start = new trie();
    
    void insert(string s){
        trie* temp = start;
        for(int i=0;i<s.size();i++){
            if(temp->v[s[i]-'a']!=NULL){
                temp=temp->v[s[i]-'a'];
            }
            else{
                temp->v[s[i]-'a'] = new trie();
                temp=temp->v[s[i]-'a'];
            }
        }
        temp->end = true;
        return ;
    }
    bool fun(string s){
        queue<pair<trie*,int>> q;
        q.push({start,0});
        int i=0;
        int n;
        trie* temp=start;
        trie* k;
        pair<trie*, int> p;
        for(i=0;i<s.size() && q.size()>0;i++){
            n = q.size();
            while(n>0){
                p = q.front();
                q.pop();
                k = p.first;
                if(p.second==1){
                    if(k->v[s[i]-'a']!= NULL){
                        q.push({k->v[s[i]-'a'],1});
                    }
                }
                else{
                    for(int j=0;j<26;j++){
                        if(k->v[j]!=NULL){
                            if(j== s[i]-'a'){
                                q.push({k->v[s[i]-'a'],0});
                            }
                            else{
                                q.push({k->v[j],1});
                            }
                        }
                    }
                }
                n--;
            }
        }
        if(i<s.size()) return false;
        while(q.size()>0){
            p = q.front();
            k=p.first;
            q.pop();
            if(p.second==1 && k->end==true) return true;
        }
        return false;
    }
    
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(int i=0;i<dictionary.size();i++){
            insert(dictionary[i]);
        }
    }
    
    bool search(string searchWord) {
        return fun(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */