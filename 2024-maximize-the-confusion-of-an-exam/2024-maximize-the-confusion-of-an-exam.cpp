class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        //we can use 2 for loop for condition. use sliding window technique na dif no. of opposite side become greater than k simply slide the window.
        
        int t=0,st=0,f=0,sf=0;
        int ans=0;
        for(int i=0;i<answerKey.size();i++){
            if(answerKey[i]=='T') t++;
            else f++;
            //check for 1st condition
            if(t>k){
                while(sf<i && answerKey[sf]=='F') sf++;
                if(sf<i) sf++;
                t--;
            }
            ans = max(ans,i-sf+1);
            if(f>k){
               while(st<i && answerKey[st]=='T') st++;
                if(st<i) st++;
                f--; 
            }
            ans = max(ans,i-st+1);
        }
        return ans;
    }
};