class Solution {
  //  In this question, at evry point i have 2 options. 
    
    
    
    
    int ans=0;
    int fun(vector<int>& nums1, vector<int>& nums2,int ind,int prev,int count,vector<vector<int>>& dp){
        //cout<<ind<<"  "<<count<<endl;
        ans = max(ans,count);
        if(ind==nums1.size()){
            return 0;
        }
        
        if(dp[ind][prev-1]!=-1) return dp[ind][prev-1];

        int diff;
        if(prev==1) diff=nums1[ind-1];
        else diff=nums2[ind-1];
        
        int k=0,p=0;
        int flag=0;
        if(nums1[ind]>=diff){
             //cout<<"yha p kitbi baar nums1 "<<ind<<" "<<count<<endl;
            k = 1+fun(nums1,nums2,ind+1,1,count+1,dp);
            flag=1;
        }
        else
         p = 1+fun(nums1,nums2,ind+1,1,1,dp);
        
        if(nums2[ind]>=diff){
            //cout<<"yha p kitbi baar nums2 "<<ind<<" "<<count<<endl;
            k= max(k,1+fun(nums1,nums2,ind+1,2,count+1,dp));
            flag=1;
        } 
        else{
            //cout<<"yha p kb kb aaya "<<ind<<endl;
          p = max(p,1+fun(nums1,nums2,ind+1,2,1,dp));
        }
        
        ans = max(ans,p);
        if(flag==1){
        ans = max(ans,k);
        return dp[ind][prev-1]=k;
        }
        
        return dp[ind][prev-1]=0;
    }
    
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
     int n = nums1.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int prev;
        if(nums1[0]<=nums2[0]) prev=1;
        else prev=2;
        int p = 1+fun(nums1,nums2,1,prev,1,dp);
        // for(int i=0;i<n;i++){
        //     cout<<dp[i][0]<<"  "<<dp[i][1]<<endl;
        // }
        return max(ans,p);
        
        
    }
};