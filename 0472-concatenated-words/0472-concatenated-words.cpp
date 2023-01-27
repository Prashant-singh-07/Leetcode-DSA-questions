class Solution {
public:
    struct trie{
        struct trie* a[26];
        bool flag=false;
        trie() {
		    memset(a,0,sizeof(a));
		    flag = false;
	    }
    };
    trie* root=new trie();
    void insert(string s){
        int i=0;
        trie* temp=root;
        for(int i=s.size()-1;i>=0;i--){
            if(temp->a[s[i]-'a']==NULL){
                temp->a[s[i]-'a']=new trie();
            }
           
               temp= temp->a[s[i]-'a'];
            
        
        }
        temp->flag=true;
    }
    
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string& w1, const string& w2) {
            return (w1.size() < w2.size());
        });
        vector<string> ans;
        int n;
        for(auto w:words){
            n = w.size();
            if(n==0) continue;
            vector<bool> dp(n+1);
            dp[0]=true;
            for(int i=0;i<n;i++){
                trie* temp=root;
                for(int j=i;j>=0;j--){
                    if(temp==NULL || temp->a[w[j]-'a']==NULL) break;
                    temp=temp->a[w[j]-'a'];
                    if(dp[j] && temp->flag){
                        dp[i+1]=true;
                        break;
                    }
                }
            }
            if(dp[n]==true) ans.push_back(w);
            insert(w);
        }
        return ans;
    }
};