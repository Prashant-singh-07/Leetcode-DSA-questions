class Solution {
public:
    int atMostDistance(vector<int>& nums,int k){
        if(k==0) return 0;
        int left=0,right=0;
        unordered_map<int,int> m;
        int n =  nums.size();
        int count=0,diff;
        while(right<n && m.size()<=k){
            if(m.size()==k){
                    if(m.find(nums[right])==m.end()) break;
                }
               
            m[nums[right]]++;
            right++;
        }
        while(left<n){
            diff = (right-left);
            count+=diff;
            //cout<<count<<" "<<left<<"    "<<right<<endl;
            m[nums[left]]--;
            if(m[nums[left]]==0) m.erase(nums[left]);
            while(right<n && m.size()<=k){
                if(m.size()==k){
                    if(m.find(nums[right])==m.end()) break;
                }
            m[nums[right]]++;
            right++;
            }
            left++;
        }
        //cout<<count<<endl;
        return count;
        
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostDistance(nums,k) - atMostDistance(nums,k-1);
    }
};