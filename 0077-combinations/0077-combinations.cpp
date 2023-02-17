class Solution {
public:
    vector<vector<int>> ans;
    void fun(int n,int k,int start,vector<int>& v){
        if(v.size()==k){
            ans.push_back(v);
            return ;
        }
        for(int i=start;i<=n;i++){
            v.push_back(i);
            fun(n,k,i+1,v);
            v.pop_back();
        }
        return ;
       
    }
    vector<vector<int>> combine(int n, int k) {
       vector<int> v;
        for(int i=1;i<=n-k+1;i++){
            v.push_back(i);
            fun(n,k,i+1,v);
            v.pop_back();
        }
        return ans;
    }
};