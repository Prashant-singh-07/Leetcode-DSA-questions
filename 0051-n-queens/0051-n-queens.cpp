class Solution {
    vector<vector<string>> ans;
    bool check(vector<vector<char>>& v,int row,int col){
        int n = v.size();
        int i=row,j=col;
        while(i<n){
            if(v[i][col]=='Q') return false;
            i++;
        }
        i=row-1;
        while(i>=0){
            if(v[i][col]=='Q') return false;
            i--;
        }
        while(j<n){
            if(v[row][j]=='Q') return false;
            j++;
        }
        j=col-1;
        while(j>=0){
            if(v[row][j]=='Q') return false;
            j--;
        }
        i=row;
        j=col;
        while(i>=0 && j<n){
            if(v[i][j]=='Q') return false;
            i--;
            j++;
        }
        i=row;
        j=col;
        while(i<n && j>=0){
            if(v[i][j]=='Q') return false;
            i++;
            j--;
        }
        
        i=row;
        j=col;
        while(i<n && j<n){
            if(v[i][j]=='Q') return false;
            i++;
            j++;
        }
        i=row;
        j=col;
        while(i>=0 && j>=0){
            if(v[i][j]=='Q') return false;
            i--;
            j--;
        }
        return true;
    }
    void fun(vector<vector<char>>& v,int ind){
        if(ind>=v.size()){
            string temp="";
            vector<string> res;
            for(int i=0;i<v.size();i++){
                for(int j=0;j<v.size();j++){
                    temp+=v[i][j];
                }
                res.push_back(temp);
                temp="";
            }
            ans.push_back(res);
            res.clear();
            return ;
        }
        for(int i=0;i<v.size();i++){
            if(check(v,i,ind)==true){
                v[i][ind]='Q';
                fun(v,ind+1);
                v[i][ind]='.';
            }
            
            
        }
        return ;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> v(n,vector<char>(n,'.'));
        fun(v,0);
        return ans;
    }
};