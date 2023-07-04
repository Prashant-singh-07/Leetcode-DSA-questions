class Solution {
public:
    int singleNumber(vector<int>& a) {
        int n = a.size();
        int t[33];
        int i,j,f;
        f=0;
    
        /*for(i=0;i<32;i++){
            t[i]=0;
        }*/
        memset(t,0,sizeof(t));
        for(i=0;i<32;i++){
            for(j=0;j<n;j++){
                if((a[j]&(1<<i))!=0){
                    t[i]=t[i]+1;
                }
            }
        }
        
        for(i=0;i<32;i++){
            f = f+ (t[i]%3)*(1<<i);
        }
        return f;
    }
};