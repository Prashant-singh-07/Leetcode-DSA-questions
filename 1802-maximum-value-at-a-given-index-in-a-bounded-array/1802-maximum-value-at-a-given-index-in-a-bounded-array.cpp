class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int low=1,high=maxSum;
        long long mid,diff,j;
        int ans;
        long long left,right,sum;
        while(low<=high){
            mid = (low+high)/2;
            left=0;
            right=0;
            sum = ((mid-1)*(mid))/2;
            if(index>0){
                left=sum;
                if(index>mid-1){
                    diff = index-mid+1;
                    left+=diff;
                }
                else if(index<mid-1){
                    diff = mid-1-index;
                    left-= ((diff)*(diff+1))/2;
                }
            }
            j = n-index-1;
            if(j>0){
                right = sum;
                if(j>mid-1){
                    diff = j-mid+1;
                    right+=diff;
                }
                    else if(j<mid-1){
                        diff = mid-1-j;
                            right-= ((diff)*(diff+1))/2;
                    }
            }
            if(left+right+mid <= maxSum){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        return ans;
    }
};