class Solution {
    long long fun(int x){
        long long res=1;
        for(int i=0;i<x;i++){
            res*=2;
        }
        return res;
    }
public:
    int minOperations(int n) {
        if(n==0) return 0;
     int mi,mx;
        int p = log2(n);
        mi = fun(p);
        mx = fun(p+1);
        int diff1 = n-mi;
        int diff2 = mx-n;
        if(diff1>diff2){
            return 1+minOperations(diff2);
        }
        else{
            return 1+minOperations(diff1);
        }
        return 0;
    }
};

