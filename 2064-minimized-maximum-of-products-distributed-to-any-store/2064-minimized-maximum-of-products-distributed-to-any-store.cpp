class Solution {
    bool check(vector<int>& v,int mid,int n){
        int temp;
        int i=0;
        for(i=0;i<v.size() && n>0;i++){
            temp=v[i];
            while(temp>0 && n>0){
                n--;
                temp-=mid;
            }
            if(temp>0 && n==0) return false;
        }
       if(i<v.size()) return false;
        return true;
        
        
       //  priority_queue<int,vector<int>,greater<int>> p;
       //  for(int i=0;i<v.size();i++) p.push(v[i]);
       //  int k;
       //  //cout<<"ye mid h "<<mid<<endl;
       //  while(p.size()>0 && n>0){
       //      k=p.top();
       //      p.pop();
       //      //cout<<k<<endl;
       //      k-=mid;
       //      if(k>0) p.push(k);
       //      n--;
       //  }
       // // cout<<p.size()<<"  ye p ka size h"<<endl;
       //  if(p.size()>0) return false;
       //  return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& v) {
        int low=1;
        int high=INT_MIN;
        long long sum=0;
        for(int i=0;i<v.size();i++){
            if(v[i]>high) high=v[i];
        }
        int mid,ans;
        while(low<=high){
            mid=(low+high)/2;
           // cout<<low<<"  "<<high<<"  "<<mid<<endl;
            if(check(v,mid,n)){
                //cout<<mid<<" yha p kon h bhai "<<low<<"  "<<high<<endl;
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};