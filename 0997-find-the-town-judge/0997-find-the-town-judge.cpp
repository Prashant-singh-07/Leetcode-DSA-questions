class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> people,judge;
        if(n==1) return 1;
        for(int i=0;i<trust.size();i++){
            people[trust[i][0]]++;
            if(people.find(trust[i][0])!=people.end()){
                if(judge.find(trust[i][0])!=judge.end()) judge.erase(trust[i][0]);
            }
            if(people.find(trust[i][1])!=people.end()){
                if(judge.find(trust[i][1])!=judge.end()) judge.erase(trust[i][1]);
            }
            else{
                judge[trust[i][1]]++;
            }
        }
        if(judge.size()==0) return -1;
        for(auto p:judge){
            if(p.second==n-1) return p.first;
        }
        return -1;
    }
};