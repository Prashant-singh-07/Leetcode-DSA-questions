class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans=0;
       vector<int> right(n+1);
        right[n]=INT_MAX;
       // right[n-1]=arr[n-1];

        for(int i=n-1;i>=0;i--){
            right[i] = min(right[i+1],arr[i]);
        }
        int left=arr[0],start=0;
        for(int i=0;i<n;i++){
            if(left<=right[i+1]){
                ans++;
                if(i+1<n) left=arr[i+1];
            }
            else{
                left = max(left,arr[i]);
            }
        }
        //if(ans==0) return 1;
       
        return ans;
    }
};