class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
       priority_queue<pair<int,int>> high;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> low;
        int n = nums1.size();
        for(int i=0;i<n;i++) {
            high.push({nums1[i],i});
            low.push({nums2[i],i});
        }
        
        long long ans=INT_MIN;
        long long sum=0,j;
        pair<int,int> p,r;
        unordered_map<int,int> m,leave;
        
        
        for(int i=0;i<k-1;i++){
            p = high.top();
            high.pop();
            m[p.second]++;
            sum+=p.first;
        }
        while(low.size()>=k){
            p = low.top();
            low.pop();
            if(m[p.second]>0){
                //cout<<"ye to phla h"<<"   ";
                while(!high.empty() && leave[high.top().second]>0) high.pop();
                if(high.size()==0) break;
                r = high.top();
                high.pop();
                m[r.second]++;
                sum+=(r.first);
                j = sum*(p.first);
                sum-=(nums1[p.second]);
                m[p.second]--;
                leave[p.second]++;
            }
            else{
                cout<<"ye to dusra h"<<"   ";
                sum+=(nums1[p.second]);
                j = sum*(p.first);
                sum-=(nums1[p.second]);
                m[p.second]--;
                leave[p.second]++;
            }
            if(j>ans){
            cout<<j<<"  "<<p.first<<"   high ka size :   "<<high.size()<<endl;
                ans=j;
            }
        }
        return ans;
    }
};