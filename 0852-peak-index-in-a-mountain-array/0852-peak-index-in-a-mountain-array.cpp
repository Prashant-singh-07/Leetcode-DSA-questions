class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0,high=arr.size()-1;
        int mid;
        if(arr.size()<3) return -1;
        while(low<=high){
            mid = (low+high)/2;
            if(mid>0 && arr[mid]>arr[mid-1] && mid<arr.size()-1 && arr[mid]>arr[mid+1]) return mid;              
            else if(mid==0) low++;
            else if(mid==arr.size()-1) high--;
            else if(arr[mid]>arr[mid-1]) low=mid+1;
            else if(arr[mid]>arr[mid+1]) high=mid-1;
            
        }
        return 0;
    }
};