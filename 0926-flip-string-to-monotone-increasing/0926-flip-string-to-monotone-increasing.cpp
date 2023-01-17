class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> zero(n,0);
        vector<int> one(n,0);
        if(s[0]=='0') zero[0]=1;
        for(int i=1;i<s.size();i++){
             zero[i]=zero[i-1];
               if(s[i]=='0') zero[i]++;
        }
        if(s[n-1]=='1') one[n-1]=1;
        for(int i=n-2;i>=0;i--){
            one[i]=one[i+1];
            if(s[i]=='1') one[i]++;
        }
        int ans=n-one[0];
        //cout<<"ye start m hi phas gya "<<ans;
        int j,k;
        for(int i=0;i<n;i++){
            j=i+1-zero[i];
            k = n-i-1;
            k = k-one[i];
            ans = min(ans,j+k);
            //cout<<ans<<"  "<<i<<endl;
        }
        ans = min(ans,n-zero[n-1]);
        return ans;
    }
};