class Solution {
public:
    static bool compare(vector<int>& v1,vector<int>& v2){
	   //sort according to the start of interval
	   //smallest interval first
        
        return v1[1]<v2[1];
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
//        vector<int> ans(n+1);
//         int res=0;
//         sort(offers.begin(),offers.end(),compare);
//         int start=0;
//         vector<int> dp;
//         dp.push_back(offers[0][1]);
//         res=offers[0][2];
//         ans[offers[0][1]]=offers[0][2];
//         for(int i=1;i<offers.size();i++){
//             start = lower_bound(dp.begin(),dp.end(),offers[i][0])-dp.begin();
//             cout<<start<<endl;
           
//                 if(start>0){
//                     //cout<<"yha p koi aaya h kkya yrr   "<<ans[dp[start-1]]<<" "<<offers[i][2]<<endl;
//                     ans[offers[i][1]] = max(ans[offers[i][1]],ans[dp[start-1]]+offers[i][2]);
//                     cout<<"yha p kya h "<<ans[offers[i][1]]<<endl;
//                 }
            
//             ans[offers[i][1]] = max(ans[offers[i][1]],offers[i][2]);

//             if(start<dp.size())
//             ans[offers[i][1]] = max(ans[dp[start]],ans[offers[i][1]]);
           
//             res=max(res,ans[offers[i][1]]);
            
//             dp.push_back(offers[i][1]);
//         }
        
//         return res;
        unordered_map<int,vector<pair<int,int>>> m;
        for(int i=0;i<offers.size();i++){
            m[offers[i][1]].push_back({offers[i][0],offers[i][2]});
        }
        vector<int> dp(n);
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            if(m[i].size()>0){
                temp = m[i];
                 for(int j=0;j<temp.size();j++){
                     dp[i]=max(dp[i],temp[j].second);
                     if(temp[j].first>0)
                     dp[i] = max(dp[i],dp[temp[j].first -1]+temp[j].second);
                 }
                
            }
            if(i>0){
                    dp[i]=max(dp[i],dp[i-1]);
                }
        }
        return dp[n-1];
        
        
    }
};