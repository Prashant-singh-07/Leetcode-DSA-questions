// class Solution {
//     private:
//     int ans=0;
//     int mod=1e9+7;
//     vector<vector<int>> dp;
//     string target;
//     unordered_map<char,vector<int>> m;
    
//     int fun(int index,vector<string>& words,int ti){  
//         if(ti==target.size()){
//             return 1;
//         }
//         int n = words[0].size();
//         int k = target.size();
//         if((n-index)<(k-ti)) return 0;
//          if(index>=words[0].size()) return 0;
//         if(dp[index][ti]!=-1) return dp[index][ti];
//         long long s=0;
//         // for(int i=0;i<words.size();i++){
//         //     for(int j=index;j<n;j++){
//         //         if(words[i][j]==target[ti]){
//         //            s+=fun(j+1,words,ti+1);
//         //         }
//         //     }
//         // }
//         for(int i=0;i<m[target[ti]].size();i++){
//             if(m[target[ti]][i]>=index){
//             s+=fun(m[target[ti]][i]+1,words,ti+1);
//             }
//         }
        
//         s=s%mod;
//         return dp[index][ti]=s;
        
//     }
// public:
//     int numWays(vector<string>& words, string t) {
//         //lets first try brute force for this question.
//         int n = t.size();
//         int k = words[0].size();
//         dp = vector<vector<int>>(k,vector<int>(n,-1));
//         target=t;
//         for(int i=0;i<words.size();i++){
//             for(int j=0;j<k;j++){
//                 m[words[i][j]].push_back(j);
//             }
//         }
//         return fun(0,words,0);
//         return ans;
//     }
// };
class Solution {
    vector<vector<int>>dp;
    vector<vector<int>>freq;
    
    long getWords(vector<string>&words, string &target, int i, int j){
        if(j == target.size())return 1;
        if(i == words[0].size() || words[0].size() - i < target.size() - j) return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        long count = 0;
        int  curPos = target[j] - 'a';
        count += getWords(words, target, i + 1, j);
        count += freq[i][curPos] * getWords(words, target, i + 1, j + 1);
        
        return dp[i][j] = count % 1000000007;
    }
public:
    int numWays(vector<string>& words, string target) {
        
        dp.resize(words[0].size(), vector<int>(target.size(), -1));
        freq.resize(words[0].size(), vector<int>(26, 0));
        
        for(int i=0; i<words.size(); i++){
            for(int j = 0; j < words[0].size(); j++){
                int  curPos = words[i][j] - 'a';
                freq[j][curPos]++;
            }
        }
        return getWords(words,target,0,0);
    }
};


