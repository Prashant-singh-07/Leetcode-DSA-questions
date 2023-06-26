class Solution {
    private:
    bool check(string s){
        int low=0;
        int high=s.size()-1;
        while(low<high){
            if(s[low]!=s[high]) return false;
            low++;
            high--;
            
        }
        return true;
    }
    int ans=0;
    void fun(string& s,string left,string right,int ind){
        if(ind==s.size()){
            if(check(left) && check(right)){
                int k = left.size();
                k *= right.size();
                ans = max(ans,k);
            }
            return ;
        }
        fun(s,left+s[ind],right,ind+1);
        //left.pop_back();
        fun(s,left,right+s[ind],ind+1);
        //right.pop_back();
        fun(s,left,right,ind+1);
    }
public:
    int maxProduct(string s) {
        string left="";
        string right="";
        fun(s,left,right,0);
        return ans;
    }
};