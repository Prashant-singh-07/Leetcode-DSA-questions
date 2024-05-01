class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int flag=0,start;
        int ans=INT_MAX;
        int ind,count;
       for(int i=0;i<3;i++) {
           flag=0;
           count=0;
           start = nums2[0]-nums1[i];
           ind = i+1;
           for(int j=1;j<nums2.size();j++){
               if(ind>=nums1.size() || count>2){
                   flag=1;
                   break;
               }
               if(nums2[j]-nums1[ind]!=start){
                   
                   count++;
                   j--;
               }
               ind++;
           }
           if(flag==0) ans = min(ans,start);
       }
        return ans;
    }
};