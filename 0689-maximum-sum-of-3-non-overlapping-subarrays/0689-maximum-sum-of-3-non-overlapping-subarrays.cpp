class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        cout<<"1st";
        // first find sum ending at each index of length k 
        int sum=0;
        int n = nums.size();
        vector<int> v(n),vend(n);
        //first go through k element
        for(int i=0;i<k;i++) sum+=nums[i];
        v[k-1]=sum;
        for(int i=k;i<n;i++){
            sum+=nums[i];
            sum-=nums[i-k];
            v[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=n-k;i--){
            sum+=nums[i];
            
        }
        vend[n-k]=sum;
        for(int i=n-k-1;i>=0;i--){
            sum+=nums[i];
            sum-=nums[i+k];
            vend[i]=sum;
        }
        cout<<"2nd";
        
        vector<vector<int>> left(n+1,vector<int>(2,0));
        vector<vector<int>> right(n+1,vector<int>(2,0));
       left[k-1][0]=v[k-1];
        left[k-1][1]=0;
        for(int i=k;i<n;i++){
            if(v[i]>left[i-1][0]){
                left[i][0]=v[i];
                left[i][1] = i-k+1;
            }
            else{
                left[i][0]=left[i-1][0];
                left[i][1]=left[i-1][1];
            }
        }
        cout<<"third";
        int ans=INT_MIN;
        right[n-k][0]=vend[n-k];
        right[n-k][1]=n-k;
        for(int i=n-1-k;i>=0;i--){
            if(vend[i]>=right[i+1][0]){
                right[i][0]= vend[i];
                right[i][1] = i;
            }
            else{
                right[i][0]=right[i+1][0];
                right[i][1]=right[i+1][1];
            }
        }
        cout<<"4th";
        vector<int> res;
        for(int i=(2*k)-1;i<=n-k-1;i++){
            cout<<endl;
            cout<<v[i]<<"  "<<left[i-k][0]<<" "<<right[i+1][0]<<endl;
            if(v[i]+left[i-k][0]+right[i+1][0]> ans){
                ans = v[i]+left[i-k][0]+right[i+1][0];
                res={left[i-k][1],i-k+1,right[i+1][1]};
            }
        }
        cout<<"5th";
        return res;
        
        
    }
};