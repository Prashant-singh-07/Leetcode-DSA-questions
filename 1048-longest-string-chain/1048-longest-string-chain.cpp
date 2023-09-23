class Solution {
public:
   
  

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string & a, const string & b){ return a.size() < b.size(); });
        
        int n = words.size();
        
        vector<int> dp(n,1);
        int k,l,count=0,ans=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(words[j].size()-words[i].size()==1){
                k=0;
                l=0;
                count=0;
                while(k<words[i].size() && l<words[j].size()){
                    if(words[i][k]==words[j][l]) k++,l++;
                    else {
                       count++;
                    
                        l++;
                    }
                }
                    if(count==0 && k==words[i].size()) dp[j] = max(dp[j],1+dp[i]);
                    else if(count==1 && l==words[j].size()) dp[j] = max(dp[j],1+dp[i]);
                    }
                else if(words[j].size()-words[i].size()==0) continue;
                else {
                    break;
                }
            }
            ans=max(ans,dp[i]);
        }
        //for(int i=0;i<n;i++) cout<<words[i]<<" "<<dp[i]<<endl;
        return ans;
    }
};