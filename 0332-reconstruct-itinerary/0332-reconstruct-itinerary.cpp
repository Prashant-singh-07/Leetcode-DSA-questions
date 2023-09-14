class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> m;
        for(int i=0;i<tickets.size();i++){
            m[tickets[i][0]].insert(tickets[i][1]);
        }
        vector<string> ans;
        if(tickets.size()==0) return ans;
        stack<string> dfs;
        dfs.push("JFK");
        string temp;
        while(dfs.size()>0){
            temp=dfs.top();
            if(m[temp].empty()){
                ans.push_back(temp);
                dfs.pop();
            }
            else{
                dfs.push(*(m[temp].begin()));
                m[temp].erase(m[temp].begin());
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};