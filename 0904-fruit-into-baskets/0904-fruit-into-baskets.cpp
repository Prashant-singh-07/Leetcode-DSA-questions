class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
       unordered_map<int,int> m;
        int i=0,start=0,ans=0;
        while(i<fruits.size()){
            m[fruits[i]]++;
            while(start<i && m.size()>2){
                m[fruits[start]]--;
                if(m[fruits[start]]==0) m.erase(fruits[start]);
                start++;
            }
            ans = max(ans,i-start+1);
            i++;
        }
        return ans;
    }
};