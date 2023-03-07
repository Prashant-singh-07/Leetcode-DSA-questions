class Solution {
public:
    long long minimumTime(vector<int>& time, int total) {
        sort(time.begin(),time.end());
        int n = time.size();
        long long low,high,mid,ans;
        low=time[0];
        high = low*total;
        ans=high;
        int count;
        while(low<=high){
            mid = (low+high)/2;
            count=0;
            for(int i=0;i<time.size();i++){
                  count+=(mid/time[i]);
                    if(count>=total) break;
            }
            if(count>=total){
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