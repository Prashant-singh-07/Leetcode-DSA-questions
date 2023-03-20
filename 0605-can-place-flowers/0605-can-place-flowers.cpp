class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0,k,flag=0,flag1=0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0) count++;
            else{
                flag1++;
                if(flag==0) count--,flag++;
                else count-=2;
                if(count>0){
                    if(count%2!=0) k=1;
                    else k=0;
                    k+=(count/2);
                    n-=k;
                    
                }
                count=0;
            }
            if(n<=0) return true;
        }
        if(flag1>0) count--;
        if(count>0){
            if(count%2!=0) k=1;
          else k=0;
            k += count/2;
            n-=k;
        }
        if(n<=0) return true;
        return false;
    }
};