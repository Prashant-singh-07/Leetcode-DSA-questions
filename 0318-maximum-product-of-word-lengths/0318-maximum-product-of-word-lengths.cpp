class Solution {
public:
    int maxProduct(vector<string>& words) {
        //lets first try brute force
        int n = words.size();
        vector<vector<int>> v(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                v[i][words[i][j]-'a']++;
            }
        }
        int flag;
        int p;
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                flag=0;
                for(int k=0;k<26;k++){
                    if(v[j][k]>0 && v[i][k]>0){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    p = words[i].size();
                    p = p*(words[j].size());
                    ans = max(ans,p);
                }
            }
        }
        return ans;
    }
};