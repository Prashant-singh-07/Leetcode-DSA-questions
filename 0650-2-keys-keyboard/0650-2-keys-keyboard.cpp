class Solution {
public:
    int ans=INT_MAX;
    void fun(int len,int n,int count,int copy){
        if(len==n){
            ans = min(ans,count);
            return ;
        }
        if(len>n) return ;
        if(copy<len){
            fun(len,n,count+1,len);
        }
        fun(len+copy,n,count+1,copy);
    }
    
    
    int minSteps(int n) {
       if(n==1) return 0;
         fun(1,n,1,1);
        return ans;
    }
};