class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        vector<int> ans;
        int n = v.size();
        int i=1,j;
        while(i<n){
//             if(v[i]>0){
//                 j=i-1;
//                 while(j>=0){
//                     if(v[j]==0) j--;
//                     else if(v[j]>0) break;
//                     else{
//                         if(v[i]+v[j]==0){
//                             v[i]=0;
//                             v[j]=0;
                            
//                         }
//                         else if(v[i]+v[j]>0){
//                             v[j]=0;
                           
//                         }
//                         else{
//                             v[i]=0;
//                             break;
//                         }
                       
//                     }
                    
//                 }
//             }
            if(v[i]<0){
                j=i-1;
                while(j>=0){
                    if(v[j]==0) j--;
                    else if(v[j]<0) break;
                    else{
                        if(v[i]+v[j]==0){
                            v[i]=0;
                            v[j]=0;
                            break;
                            
                        }
                        else if(v[i]+v[j]>0){
                            v[i]=0;
                            break;
                           
                        }
                        else{
                            v[j]=0;
                        }
                        
                    }
                    
                }
            }
            i++;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]!=0) ans.push_back(v[i]);
        }
        return ans;
    }
};