class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0;
        int n = arr.size();
        int high=n-1;
        int mid;
        while(low<=high){
            mid = (low+high)/2;
            if(mid==0) low=mid+1;
            else if(mid==-1) high=mid-1;
            else if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid]>arr[mid-1]) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};