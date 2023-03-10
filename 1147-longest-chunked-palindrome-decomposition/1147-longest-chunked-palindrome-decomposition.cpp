class Solution {
    private:
    bool check(string text,int k){
        int n = text.size();
        int start=0,end=n-1;
        int count=0;
        int res=0;
        while(start+count<end-count){
            if(text.substr(start,count+1) == text.substr(end-count,count+1)){
                res+=2;
                if(res>=k) return true;
                start=start+count+1;
                end = end-count-1;
                count=0;
                if(start<=end){
                    if(k%2!=0 && res==k-1) return true;
                }
            }
            else
            count++;
        }
        
        return false;
    }
public:
    int longestDecomposition(string text) {
        int start,end;
        start=1;
        end = text.size();
        int mid,ans=1;
        while(start<=end){
            mid = (start+end)/2;
            cout<<start<<" "<<end<<endl;
            if(check(text,mid)){
                
                ans = mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};