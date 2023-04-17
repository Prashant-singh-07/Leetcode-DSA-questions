class Solution {
public:
    int numRabbits(vector<int>& answers) {
       unordered_map<int,int> m;
        for(int i=0;i<answers.size();i++){
            m[answers[i]]++;
        }
        int j,k,count=0;
        for(auto p:m){
            j=p.first +1;
            k=p.second;
            while(k>0){
                count+=j;
                k-=j;
            }
        }
        return count;
    }
};