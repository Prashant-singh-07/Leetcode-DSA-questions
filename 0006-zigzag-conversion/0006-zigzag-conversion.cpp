class Solution {
public:
    string convert(string s, int rows) {
        if(rows==1) return s;
        string ans="";
        vector<vector<char>> v(rows);
        int up=0,down=1;
        int ind=0;
        //vector<char> v(rows,'.');
        for(int i=0;i<s.size();i++){
            if(down==1){
                v[ind].push_back(s[i]);
                ind++;
                if(ind==rows){
                    down=0;
                    up=1;
                    ind=rows-2;
                }
            }
            else if(up==1){
                v[ind].push_back(s[i]);
                ind--;
                if(ind==-1){
                    down=1;
                    up=0;
                    ind=1;
                }
            }
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                ans+=v[i][j];
            }
        }
        return ans;
    }
};