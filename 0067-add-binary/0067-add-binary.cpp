class Solution {
public:
    string addBinary(string a, string b) {
       int m = a.size();
        int n = b.size();
        int rem=0;
        
        int diff = abs(m-n);
        for(int i=0;i<diff;i++){
            if(m>n) b = '0'+b;
            else a = '0'+a;
        }
        int x;
        if(m>n) x=m;
        else x=n;
        string ans="";
        while(x>0){
            cout<<x<<" "<<rem<<endl;
            if(a[x-1]==b[x-1]){
                if(rem>0) ans = '1'+ans;
                else ans = '0'+ans;
                
                if(a[x-1]=='0') rem=0; 
                else rem=1;
            }
            else{
                if(rem>0){
                    ans = '0'+ans;
                }
                else{
                    ans = '1'+ans;
                }
            }
            x--;
        }
        if(rem>0) ans = '1'+ans;
        return ans;
    }
};