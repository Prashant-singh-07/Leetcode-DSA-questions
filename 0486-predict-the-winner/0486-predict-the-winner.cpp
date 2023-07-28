class Solution {
    long long fun(vector<int>& nums,int start,int last){
        if(start>last) return 0;
        if(start==last) return nums[start];
        long long l = fun(nums,start+2,last);
        long long k = fun(nums,start+1,last-1);
       
        if(l>=k) l=k;
        l+=nums[start];
        long long r = fun(nums,start,last-2);
        
        if(r>=k) r=k;
        r+=nums[last];
        //cout<<l<<"  "<<r<<endl;
        if(l>r) return l;
        return r;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        // // i have 2 options here, either take it from last or first.
        // if i choosing element then player 2 will play optimally
        long long sum=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long long k = fun(nums,0,n-1);
        if(sum-k > k) return false;
        return true;
    }
};