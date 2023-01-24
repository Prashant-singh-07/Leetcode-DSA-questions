class Solution {
public:
    int minimumTime(string s) {
//         //Lets jump into question
//         we have 3 options:-
//             1) remove left 
//             2) remove right
//             3)remove any middle one
//             Now which option can we execute during
//  a specific condition:
//         1st condition:- if i am at index where either left index or right index has 1 then i will go with 1 char side.
//         2nd condition:- if both left and right has 1 one then i will go with both direction one by one.
//         3rd condition:- if both left and right have 0 thrn here i will try to experiment with all these three steps.
            
//     1st major problem:- how to choose that which middle i have to explode first.z
        
        int n = s.size();
        vector<int> dp(n+1);
        int step=0,count=0;
        int last=0;
        if(s[0]=='0') dp[0]=0,count++;
        else dp[0]=1,last=1;
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                count++;
                dp[i]=dp[i-1];
                
            }
            else{
                dp[i] = min(i+1,2+last);
                last = dp[i];
            }
        }
        vector<int> right(n+1);
        if(s[n-1]=='0') right[n-1]=0;
        else right[n-1]=1,last=1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0'){
                count++;
                right[i]=right[i+1];
            }
            else{
                right[i] = min(n-i,2+last);
                last = right[i];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                ans = min(ans,dp[i]+right[i+1]);
                //cout<<dp[i]+right[i+1]<<"  "<<i<<"  "<<"yha se 7 aaya h "<<endl;
            }
        }
       
        ans=min(ans,dp[n-1]);
        
        ans=min(ans,right[0]);
       if(ans==INT_MAX) return 0;
        return ans;
        
    }
};