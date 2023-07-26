class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int high = 1e9;
        int low=1,mid;
        int n = dist.size();
        double sum=0.00;
        double k;
        int ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            sum=0.00;
            for(int i=0;i<n-1;i++){
                if(dist[i]%mid!=0) sum+=1.00;
                if(mid<=dist[i]){
                k = double(dist[i]/mid);
                sum+=k;
                }
                //cout<<sum<<endl;
            }
            k = double(dist[n-1])/double(mid);
            sum+=k;
            //sum=round(sum * 100.0) / 100.0; 
            //cout<<sum<<endl;
            //cout<<sum<<"  ";
            if(sum<=hour){
                if(ans==-1) ans=mid;
                else ans=min(ans,mid);
                
                high=mid-1;
            }
            else if(sum>hour) low=mid+1;
        }  
        return ans;
    }
};