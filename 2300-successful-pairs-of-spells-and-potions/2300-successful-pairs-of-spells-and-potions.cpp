class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        
        sort(potions.begin(),potions.end());
        int low,high,mid,curr;
        long long prod;
        int m = potions.size();
        vector<int> ans;
        for(int i=0;i<spells.size();i++){
            low=0;
            high=m-1;
            curr=0;
            while(low<=high){
                mid = (low+high)/2;
                prod = potions[mid]*  1LL * spells[i];
                if(prod<success){
                    low=mid+1;
                }
                else{
                    curr = max(curr,m-mid);
                    high=mid-1;
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};