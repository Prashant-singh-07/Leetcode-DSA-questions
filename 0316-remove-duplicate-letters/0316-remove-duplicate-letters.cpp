class Solution {
    vector<string> ans;
public:
    string removeDuplicateLetters(string s) {
       vector<int> l(26);
        for(int i = 0;i<s.size();i++){
            l[s[i]-'a']=i;
            
        }
        vector<int> visited(26);
        string str = "";
    
        int j=0,i=0;
        int n = s.size();
        cout<<"ye chla "<<endl;
        while(i<n){
            cout<<"iske baad bhi chla "<< i<<endl;
            //int c = str[i]-'a'
            if(visited[s[i]-'a']==1){
                i++;
                continue;
            }
           //cout<<" iske baad nhi chl rha h kya "<<endl;
            //char c = 
            while(j>0 && s[i]<str[j-1] && l[str[j-1]-'a']>i){
                cout<<"isme dikkat aa skata h  "<<j<< " "<<str<<endl;
                visited[str[j-1]-'a'] = 0;
                str.pop_back();
                 j--;
            }
             str.push_back(s[i]);
            j++;
             visited[s[i]-'a']= 1;
            i++;
            
        }
        return str;
    }
};