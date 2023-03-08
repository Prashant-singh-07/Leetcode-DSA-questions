class Solution {
    private:
    bool check(vector<int>& piles,int val,int h){
        int count=0;
        int q,r;
        for(int i=0;i<piles.size();i++){
            if(piles[i]<val) count++;
            else{
                q = piles[i]/val;
                r = piles[i]%val;
                count+=q;
                if(r>0) count++;
            }
            if(count>h) return false;
        }
        return true;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high,low,mid;
        high=INT_MIN;
        for(int k:piles){
            high=max(high,k);
        }
        low=1;
        int ans;
        while(low<=high){
            mid = (low+high)/2;
            if(check(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};