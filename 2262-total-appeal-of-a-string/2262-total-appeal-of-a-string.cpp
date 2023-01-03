class Solution {
public:
    long long appealSum(string s) {
        long long sum=0, prev=0;
        int freq[128];
        for(int i=0;i<128;i++)freq[i]=-1;
        
        for(int i=0;i<s.size();i++){
            if(freq[s[i]]==-1)
                prev+=i+1;
            else
                prev+=i-freq[s[i]];
                
            freq[s[i]]=i;
            sum+=prev;
        }
        return sum;
    }
};