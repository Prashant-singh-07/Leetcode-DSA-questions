class Solution {
    int count1=0,count2=0;
    void fun(int n){
        if(n%2==0){
            count1++;
            fun(n/2);
        }
        else if(n%5==0){
            count2++;
            fun(n/5);
        }
    }
public:
    int trailingZeroes(int n) {
        for(int i=2;i<=n;i++)
        fun(i);
        
        return min(count1,count2);
    }
};