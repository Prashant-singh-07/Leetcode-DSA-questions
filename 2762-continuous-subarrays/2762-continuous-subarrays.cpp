// class Solution {
// public:
//     long long continuousSubarrays(vector<int>& nums) {
//         long long ans=1;
//         multiset<pair<int,int>> m;
//         m.insert({nums[0],0});
//         pair<int,int> p;
//         int high,low;
//         for(int i=1;i<nums.size();i++){
//            low = m.lower_bound({nums[i]-3,0}) - m.begin();
//             high = m.upper_bound({nums[i]+3,0}) - m.begin();
//             low = 
//         }
//     }
// };

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
            
            
            int l = 0, r = 0,j = 0;
            
            long long ans = 0;
            
            for(int i = 0;i<nums.size();i++){
                    
                    if(i == 0){ // First element
                            ans = ans + 1;
                            l = nums[i] - 2;  // range from a - 2
                            r = nums[i] + 2; // rane to a + 2
                    }else if(nums[i] >= l && nums[i] <= r){ // If new element belong to same range then 
                                    
                                    l = max(l,nums[i]-2); // take max from (a-2,b-2)
                                    r = min(r,nums[i]+2); // take min from (a+2,b+2)
                                    ans = ans + (i-j+1); // add subarray to answer
                                    
                    }else{ // If doest not belong to ranges try to remove from i-1 
                                  
                                   j = i-1;
                                   l = nums[i] - 2 , r = nums[i] + 2;  // new ranges
                                   while(nums[j]  >= nums[i] - 2 && nums[j] <= nums[i] + 2){
                                           
                                           l = max(l,nums[j] - 2); // take max 
                                           r = min(r,nums[j] + 2); // take min
                                           j--;
                                           
                                   }
                                   j++; 
                                    
                                  
                                   ans = ans + (i-j+1); 
                            
                    }
            }
            
            
            
            
            return ans;
        
    }
};