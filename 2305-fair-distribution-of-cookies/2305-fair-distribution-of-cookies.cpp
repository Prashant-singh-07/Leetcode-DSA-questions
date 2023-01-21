class Solution {
public:
    int ans=INT_MAX;
    void fun(vector<int>& cookies,int k,int ind,vector<int>& kid){
        if(ind==cookies.size()){
            int m=INT_MIN;
            for(auto p:kid) m=max(m,p);
            ans = min(m,ans);
            return ;
        }
        
        for(int i=0;i<k;i++){
            kid[i]+=cookies[ind];
            fun(cookies,k,ind+1,kid);
            kid[i]-=cookies[ind];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
       vector<int> kid(k,0);
        fun(cookies,k,0,kid);
        return ans;
    }
};