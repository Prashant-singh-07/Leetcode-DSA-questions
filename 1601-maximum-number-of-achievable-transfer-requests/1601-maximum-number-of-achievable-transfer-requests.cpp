class Solution {
    private:
    int ans=0;
    void fun(vector<vector<int>>& req,int ind,vector<int>& diff,int count){
        
        if(ind==req.size()){
            int flag=0;
            for(int i=0;i<diff.size();i++){
                if(diff[i]!=0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                ans = max(ans,count);
            }
            return ;
            
        }
        
        diff[req[ind][0]]--;
        diff[req[ind][1]]++;
        fun(req,ind+1,diff,count+1);
        diff[req[ind][0]]++;
        diff[req[ind][1]]--;
        fun(req,ind+1,diff,count);
        return ;
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> diff(n);
        fun(requests,0,diff,0);
        return ans;
    }
};