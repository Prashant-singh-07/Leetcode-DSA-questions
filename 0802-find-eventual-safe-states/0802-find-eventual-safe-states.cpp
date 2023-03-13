class Solution {
public:
    //vector<int> check;
    bool fun(vector<vector<int>>& v,int ind,vector<int>& check){
        //cout<<ind<<endl;
        if(check[ind]!=-1){
            if(check[ind]) return true;
            return false;
        }
        bool k =true;
        check[ind]=false;
        for(int i=0;i<v[ind].size();i++){
            if(v[ind][i]==ind){
                k=false;
                break;
            }
            k = k & fun(v,v[ind][i],check);
        }
        check[ind] = k?1:0;
        return k;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> check(n+1,-1);
       // check=v;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(check[i]==1 || graph[i].size()==0){
                ans.push_back(i);
            }
            else if(check[i]==0){
                continue;
            }
            else{
                if(fun(graph,i,check)){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};