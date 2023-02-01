class Solution {
public:
    int fun(long long res,long long base,int n){
        int mod = 1e9+7;
        while(n>0){
            if(n&1){
                res = (res*base)%mod;
            }
            base=(base*base)%mod;
            n=n/2;
        }
        return (res-2+mod)%mod;
    }
    int monkeyMove(int n) {
        return fun(1,2,n);
    }
};