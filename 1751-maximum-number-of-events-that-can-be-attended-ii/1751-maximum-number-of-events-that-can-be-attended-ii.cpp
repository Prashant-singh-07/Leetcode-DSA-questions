 bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
       
    return v1[1] < v2[1] ;
}

class Solution {
public:
   
//     int fun(vector<vector<int>>& events, int k,int ind,int end,vector<vector<int>>& dp){
//         if(ind==events.size()){  
//             return 0;
//         }
//         if(k==0) return 0;
        
//         //two choices here, either leave or select
        
//         //if(dp[ind][k-1]!=-1) return dp[ind][k-1];
        
//         int ans=0;
//         if(events[ind][0]>end){
//             ans = events[ind][2]+fun(events,k-1,ind+1,events[ind][1],dp);
//         }
//         ans = max(ans,fun(events,k,ind+1,end,dp));
//         return dp[ind][k-1] = ans;
//     }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end(),sortcol);
        int n = events.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        vector<int> lastu(n);
        for(int i=0;i<events.size();i++){
            lastu[i]=events[i][1];
            cout<<events[i][0]<<" "<<events[i][1]<<"  "<<events[i][2]<<endl;
        }
        int low,ans=0;
        dp[0][1]=events[0][2];
        ans=max(ans,dp[0][1]);
        for(int i=1;i<n;i++){
            low = lower_bound(lastu.begin(),lastu.end(),events[i][0]) - lastu.begin();
            // if(low==0 || low>i){
            //     dp[i][1]=max(dp[i-1][1],events[i][2]);
            //     ans=max(ans,dp[i][1]);
            //     continue;
            // }
            for(int j=1;j<=k;j++){
                if(j==1){
                        dp[i][j]=max(dp[i-1][j],events[i][2]);
                        //cout<<"yha to aay ah"<<dp[i][j]<<endl;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                      if(low>0)
                        dp[i][j] = max(dp[i][j],events[i][2]+dp[low-1][j-1]);
                    dp[i][j]=max(dp[i][j],dp[i][j-1]);
                        
                }
               
                ans = max(ans,dp[i][j]);
            
            }
            cout<<endl;
            
        }
        // for(int i=0;i<n;i++){
        //     for(int j=1;j<=k;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
        
        
        // return fun(events,k,0,-1,dp);
        
    }
};