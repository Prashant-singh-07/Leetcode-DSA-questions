class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> m;
        string s;
        int j,flag;
        int k,num,temp1,temp2,count;
        for(int i=0;i<formula.size();i++){
            if(formula[i]>=65 && formula[i]<=90){
                s="";
                flag=0;
                s+=formula[i];
                j = i+1;
                while(j<formula.size() && formula[j]>=97 && formula[j]<=122){
                    s+=formula[j];
                    j++;
                }
                            num=0;
                            k=0;
                           
                            while(j<formula.size() && formula[j]<='9' && formula[j]>='0'){
                                temp1=pow(10,k);
                                k++;
                                temp2 = formula[j]-'0';
                                num = (num*temp1)+temp2;
                                j++;
                                
                            }
                //cout<<num<<endl;
                if(num!=0)
                count=num;
                else count=1;
                for(;j<formula.size();j++){
                    if(formula[j]=='(') flag++;
                    else if(formula[j]==')'){
                        if(flag>0) flag--;
                        else{
                            j++;
                            num=0;
                            k=0;
                            
                            while(j<formula.size() && formula[j]<='9' && formula[j]>='0'){
                                temp1=pow(10,k);
                                k++;
                                temp2 = formula[j]-'0';
                                num = (num*temp1)+temp2;
                                j++;
                                
                            }
                            j--;
                            if(num!=0)
                            count*=num;
                            else
                                count*=1;
                        }
                    }
                }
                m[s]+=count;
            }
            
        }
     string ans="";
        
        for(auto p:m){
            ans+=p.first;
            //cout<<p.second;
            if(p.second>1)
            ans+=to_string(p.second);
        }
        return ans;
    }
};