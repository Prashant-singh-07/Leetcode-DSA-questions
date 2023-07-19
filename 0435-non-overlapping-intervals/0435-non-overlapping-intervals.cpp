class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        if(n<=1) return 0;
        int left=0,right=1,count=0;
       while(right<n){
           if(intervals[right][1]<=intervals[left][1]){
               count++;
               left=right;
               right++;
           }
           else if(intervals[right][0]<intervals[left][1]){
               count++;
               right++;
           }
           else{
               left=right;
               right++;
           }
       }
        return count;
    }
};