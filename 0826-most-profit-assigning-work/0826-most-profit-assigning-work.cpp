class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        int ans=0;
        for(int i=0;i<profit.size();i++)
        {
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        int i=0;
        int curr=0;
        int n = profit.size();
        sort(worker.begin(),worker.end());
        for(int j=0;j<worker.size();j++){
            while(i<profit.size() && v[i].first<=worker[j]) curr=max(curr,v[i].second), i++;
            ans+=curr;
            // if(i==profit.size()) ans+=v[n-1].second;
            // else if(v[i].first>worker[j]){
            //     if(i>0){
            //         ans+=v[i-1].second;
            //     }
            // }
            
        }
        return ans;
    }
};