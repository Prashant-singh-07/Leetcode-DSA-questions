class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& spec) {
        // firstly we are going to apply dijkistra algorithm for solving this question.
        
    int startx = start[0];
        int starty=start[1];
        int targetx=target[0];
        int targety = target[1];
        
        int n = spec.size();
         int ans = abs(targetx-startx) + abs(targety-starty);
        vector<int> dp(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            dp[i] = abs(spec[i][0]-startx)+abs(spec[i][1]-starty)+spec[i][4];
            pq.push({dp[i],i});
        }
        int temp;
        while(!pq.empty()){
            auto[dc,c] = pq.top();
            pq.pop();
            if(dp[c]!=dc) continue;
            
            ans = min(ans,abs(targetx-spec[c][2])+abs(targety-spec[c][3])+dc);
            
            for(int nxt=0;nxt<n;nxt++){
                temp = abs(spec[nxt][0]-spec[c][2])+abs(spec[nxt][1]-spec[c][3])+dc+spec[nxt][4];
                if(temp<dp[nxt]){
                    dp[nxt]=temp;
                    pq.push({temp,nxt});
                }
            }
            
        }
        return ans;
        
    }
};