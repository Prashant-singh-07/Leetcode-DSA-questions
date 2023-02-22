class Solution {
    private:
    bool check(vector<int>& weights,int lim,int days){
        int sum=0,count=1;
        int i;
        for(i=0;i<weights.size();i++){
            if(count>days) return false;
            if((sum+weights[i])<=lim){
                sum+=weights[i];
            }
            else{
                if(weights[i]>lim) return false;
                sum=weights[i];
                count++;
            }
        }
        if(count>days) return false;
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum=0;
        int sz = n/days;
        if(n%days!=0) sz++;
        int m = INT_MIN;
        vector<int> v(n);
       // v[0]=weights[0];
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(i-sz+1>0){
                v[i]=sum-v[i-sz+1];
            }
            else{
                v[i]=sum;
            }
            m= max(m,v[i]);
        }
        int high=m;
        int low =1,ans=INT_MAX,mid;
        while(low<=high){
            mid = (low+high)/2;
            if(check(weights,mid,days)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
       return ans; 
    }
};