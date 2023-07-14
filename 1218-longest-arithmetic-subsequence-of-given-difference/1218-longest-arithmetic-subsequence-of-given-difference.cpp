class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> m;
        
        int ans=1,sum;
        
        for(int i=0;i<arr.size();i++){
            sum=1;
            if(m.find(arr[i]-difference)!=m.end()){
                sum +=m[arr[i]-difference];
                ans=max(ans,sum);
            }
            m[arr[i]]=sum;  
        }
        return ans;
    }
};