class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_map<string,int> m;
        int n = word.size();
        
        for(int i=0;i<forbidden.size();i++){
            m[forbidden[i]]++;
        }
        vector<int> v(n,-1);
        string temp="";
        for(int i=0;i<n;i++){
            temp="";
            for(int j=i;j<i+10 && j<n;j++){
                temp+=word[j];
                if(m.find(temp)!=m.end()){
                    v[j]=i;
                }
            }
        }
        int ans=0;
        int last=-1;
        for(int i=0;i<n;i++){
            //cout<<v[i]<<" ";
            if(v[i]!=-1){
                last = max(last,v[i]);
            }
            if(last<i){
                ans = max(ans,i-last);
            }
        }
        return ans;
    }
};