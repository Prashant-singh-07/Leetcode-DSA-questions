class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int i=n-1;
        vector<int> ans;
        int carry=0,last,sum;
        while(k>0 || i>=0){
            last = k%10;
            if(k>0 && i>=0)
            sum=num[i]+last+carry;
            else if(i>=0)
                sum=num[i]+carry;
            else if(k>0)
                sum=(k%10)+carry;
            ans.push_back(sum%10);
            if(sum<10) carry=0;
            else carry = sum/10;
            k=k/10;
            i--;
        }
        while(carry>0){
            ans.push_back(carry%10);
            carry=carry/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};