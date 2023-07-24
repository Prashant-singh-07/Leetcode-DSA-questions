class Solution {
    private:
    double fun(double x,int n){
        if(n==0) return 1.00;
        if(n==1) return x;
        if(n<0){
            double p = 1/x;
           
            if(n%2==0){
                 x= (1/x)*(1/x);
                n = (n)/2;
                n=0-n;
                return fun(x,n);
            }
             x= (1/x)*(1/x);
                n = (-n)/2;
            return p*fun(x,n);
        }
        else {
            if(n%2==0){
                return fun(x*x, n/2);
            }
            else{
                return x*fun(x*x,n/2);
            }
        }
    }
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        
        return fun(x,n);
    }
};