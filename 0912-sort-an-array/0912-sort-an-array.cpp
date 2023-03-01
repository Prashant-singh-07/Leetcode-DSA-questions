class Solution {
    private:
    void merge(vector<int>& nums,int start,int mid,int end){
        int temp = mid;
        vector<int> res(end-start+1);
        int ind=0;
        int i=start;
        while(i<mid && temp<=end){
            if(nums[i]>nums[temp]){
                res[ind]=nums[temp];
                temp++;
            }
            else{
                res[ind]=nums[i];
                i++;
            }
            ind++;
        }
        while(i<mid) res[ind]=nums[i],i++,ind++;
        while(temp<=end) res[ind]=nums[temp],temp++,ind++;
        ind=0;
        for(int i=start;i<=end;i++){
            nums[i]=res[ind];
            ind++;
        }
        return ;
    }
    
    void mergesort(vector<int>& nums,int start,int end){
        if(start<end){
            int mid = (start+end)/2;
            mergesort(nums,start,mid);
            mergesort(nums,mid+1,end);
            merge(nums,start,mid+1,end);
        }
        return ;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        //lets rty merge sort
        int start=0;
        int end=nums.size()-1;
        mergesort(nums,start,end);
        return nums;
    }
};