class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // choose k pairs and return sum of profit of highest k progits.
        vector<pair<int,int>> v;
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        int temp;
        priority_queue<int> p;
        int count=0;
        
        for(int i=0;i<profits.size();i++)
        {
            if(v[i].first<=w) p.push(v[i].second);
            else{
                if(p.size()==0) return w;
                temp=p.top();
                w+=temp;
                count++;
                if(count==k) return w;
                p.pop();
                i--;
            }
        }
        while(!p.empty() && count<k){
            temp=p.top();
            w+=temp;
            count++;
            p.pop();
        }
        return w;
    }
};