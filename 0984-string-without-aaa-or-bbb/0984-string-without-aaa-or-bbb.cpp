class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans="";
        int ca=0,cb=0;
        for(int i=0;i<(a+b);i++){
           if((a-ca)>(b-cb)){
               if(a-ca>1){
                ans+="aa";
                   i++;
                   ca+=2;
               }
               else{
                   ans+="a";
                   ca++;
               }
               if(b-cb>0){
               ans+="b";
                   i++;
                   cb++;
               }
               
               
           }
            else if((b-cb)>(a-ca)){
                if(b-cb>1){
                ans+="bb";
                    i++;
                     cb+=2;
                }
                else{
                    ans+="b";
                    cb++;
                }
                if(a-ca>0){
                ans+="a";
                i++;
                    ca++;
                }
               
                
            }
            else{
                while(ca<a && cb<b){
                    if(ans.size()>0 && ans[ans.size()-1]=='b'){
                    ans+="a";
                    ans+="b";
                    }
                    else{
                        ans+="b";
                        ans+="a";
                    }
                    ca++;
                    cb++;
                }
                break;
            }
        }
        return ans;
    }
};