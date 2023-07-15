class Solution {
    bool check(string s,int flag){
        int low=0,high=s.size()-1;
        int n = s.size();
        string temp;
        while(low<high){
            if(s[low]!=s[high]){
                cout<<flag<<" "<<s[low]<<" "<<s[high]<<endl;
                if(flag==1) return false;
                temp="";
                if(low>=0)
                temp=s.substr(0,low);
                if(low+1<n)
                temp+=s.substr(low+1,n-low-1);
                if(check(temp,1)) return true;
                temp="";
                if(high>0)
                temp=s.substr(0,high);
                
                if(high+1<n)
                temp+=s.substr(high+1,n-high-1);
                
                if(check(temp,1)) return true;
                
                
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        return check(s,0);
    }
};