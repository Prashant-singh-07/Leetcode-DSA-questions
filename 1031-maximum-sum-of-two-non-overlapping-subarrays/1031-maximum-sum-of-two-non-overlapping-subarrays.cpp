class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        //My approach would be that, firstly i would find all subarray with length firstlen from left and right and store this into index;
        int n = nums.size();
        int sum=0;
        vector<int> left(n),right(n);
        for(int i=0;i<firstLen-1;i++) sum+=nums[i];
        for(int i=firstLen-1;i<n;i++){
            sum+=nums[i];
            left[i]=sum;
            sum-=nums[i-firstLen+1];
        }
        sum=0;
        int count=0,ind;
        for(int i=n-1;i>=0;i--){
            if(count==firstLen-1){
                ind=i;
                break;
            }
            count++;
            sum+=nums[i];
        }
        for(int i=ind;i>=0;i--){
            sum+=nums[i];
            right[i]=sum;
            sum-=nums[i+firstLen-1];
        }
        for(int i=1;i<n;i++){
            left[i]=max(left[i],left[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i],right[i+1]);
            cout<<right[i]<<" ";
        }
        cout<<endl;
        //Now start checking for secondlen;
        sum=0;
        for(int i=0;i<secondLen-1;i++){
            sum+=nums[i];
        }
        int ans=INT_MIN;
        for(int i=secondLen-1;i<n;i++){
            sum+=nums[i];
            if(i-secondLen>=firstLen-1) ans=max(ans,sum+left[i-secondLen]);
            if(n-1-i>=firstLen) ans=max(ans,sum+right[i+1]);
            cout<<i<<" "<<sum<<" "<<ans<<endl;
            sum-=nums[i-secondLen+1];
        }
        return ans;
        
        
    }
};