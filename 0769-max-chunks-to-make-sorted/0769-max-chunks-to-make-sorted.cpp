class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum=0,ans=0,start;
        int n = arr.size();
        vector<int> v(n);
        int diff,flag=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            v[i]=sum;
        }
        //int flag=0;
        for(int i=0;i<n;i++){
            if(flag==0){
                sum = (i*(i+1))/2;
                if(sum==v[i]) ans++,flag++,start=i;;
                
            }
            else if(flag==1){
                diff = (start*(start+1))/2;
                sum = (i*(i+1))/2;
                sum-= diff;
                if(v[i]-v[start] == sum) ans++,flag++,start=i;
               
            }
            else{
                diff = (start*(start+1))/2;
                sum = (i*(i+1))/2;
                sum-= diff;
                if(v[i]-v[start] == sum) ans++,flag++,start=i;
                
            }
        }
        if(flag==0) return 1;
        return ans;
    }
};