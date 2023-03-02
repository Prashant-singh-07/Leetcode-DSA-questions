class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i=0;
        char c;
        int count=1;
        int ans=0;
        int j=0;
        int p;
        vector<char> v;
        while(i<n){
            c = chars[i];
            ans++;
            count=1;
            i++;
            while(i<n && c==chars[i]) i++,count++;
            if(count>1){
                while(count>0){
                    ans++;
                    p = count%10;
                    v.push_back('0'+p);
                    count=count/10;
                }
            }
            chars[j]=c;
            j++;
            if(v.size()>0){
                reverse(v.begin(),v.end());
                for(int h=0;h<v.size();h++){
                    chars[j]=v[h];
                    j++;
                }
                v.clear();
            }
            
            
        }
        while(chars.size()>ans) chars.pop_back();
        return ans;
    }
};