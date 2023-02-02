class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        
        long long exp=0,sum=0,run;
        int start=0;
        priority_queue<pair<int,int>> pq;
        int charge=INT_MIN;
        int ans=0;
        for(int i=0;i<runningCosts.size();i++){
            pq.push({chargeTimes[i],i});
            sum+=runningCosts[i];
            charge=pq.top().first;
            run = sum*(i-start+1);
            while(start<i && run+charge>budget){
                while(!pq.empty() && pq.top().second<=start) pq.pop();
                sum-=runningCosts[start];
                start++;
                run = sum*(i-start+1);
                charge = pq.top().first;
                
            }
            cout<<run+charge<<"  ";
            if(run+charge>budget && start==i){
                sum=0;
                while(!pq.empty()){
                pq.pop();
                }
                start=i+1;
            }
            else
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};