class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start=0;
        int count=0,diff=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]-start > 1){
                diff = arr[i]-start-1;
                if(diff+count>=k){
                    diff = k-count;
                    return start+diff;
                    break;
                }
                else count+=diff;
            }
            start=arr[i];
        }
        while(count<k){
            start++;
            count++;
        }
        return start;
    }
};