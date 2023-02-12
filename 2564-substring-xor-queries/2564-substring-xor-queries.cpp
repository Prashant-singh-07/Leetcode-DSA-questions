class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int k;
        unordered_map<int,vector<int>> m;
        vector<vector<int>> ans;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<31 && i+j<s.size();j++){
              k = stoi(s.substr(i,j+1),0,2);
                if(m.find(k)==m.end()) m[k] = {i,i+j};
                else{
                    if(j<m[k][1]-m[k][0]) m[k] = {i,i+j};
                }
            }
        }
        for(int i=0;i<queries.size();i++){
            k = queries[i][0]^queries[i][1];
            if(m.find(k)!=m.end()){
                ans.push_back(m[k]);
            }
            else{
                ans.push_back({-1,-1});
            }
        }
        return ans;
    }
};