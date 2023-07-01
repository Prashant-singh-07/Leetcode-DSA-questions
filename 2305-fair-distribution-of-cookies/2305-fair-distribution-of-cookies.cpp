class Solution {
    private:
    int ans=INT_MAX;
    void fun(vector<int>& cookies,int k,int ind,vector<int>& v){
        
        int temp=0;
        if(ind==cookies.size()){
            for(int i=0;i<k;i++){
                temp=max(temp,v[i]);
            }
            ans = min(ans,temp);
            return ;
        }
        
        for(int i=0;i<k;i++){
            // I have 2 options here
            v[i]+=cookies[ind];
            fun(cookies,k,ind+1,v);
            v[i]-=cookies[ind];
        }
        return ;
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
      int n = cookies.size();
        sort(cookies.begin(),cookies.end());
       // vector<vector<int>> v(k,vector<int>(1<<n,-1));
        vector<int> v(k);
        int mask=0;
        fun(cookies,k,0,v);
        return ans;
    }
};