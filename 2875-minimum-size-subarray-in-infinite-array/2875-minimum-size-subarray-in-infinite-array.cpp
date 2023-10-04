class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
//         int left=0,right=0;
//         unordered_map<long long,int> m;
//         long long sum=0,curr=0;
//         int n = nums.size();
//         int ans=INT_MAX;
//         while(right<n){
//             sum+=nums[right];
//             m[sum]=right;
//             curr+=nums[right];
//            // cout<<left<<" "<<curr<<endl;
//                 while(curr>target && left<=right){
                   
//                     curr-=nums[left];
//                     left++;
//                     //cout<<curr<<endl;
//                 }
//             //cout<<" ab curr kitna h "<<curr<<endl;
            
//             if(curr==target){
//                 //cout<<left<<"  "<<right<<endl;
//                 ans = min(ans,right-left+1);
//                 curr-=nums[left];
//                 left++;
//             }
//             right++;
            
//         }
//         //cout<<"left to ye aaya h bhai "<<left<<endl;
//         int k,q,l;
//         if(left==0){ //It means that it got nothing
//              //cout<<"isme aaya h brooooo ";
//             if(target%sum==0) return (target/sum)*n;
//             k = target%sum;
//             if(m.find(k)!=m.end()) return (target/sum)*n + m[k]+1;

            
//             for(auto p:m){
//                 q = sum-p.first;
//                 //cout<<k<<" "<<p.first<<endl;
//                 k = (target-q)%sum;
//                q = (target-q)/sum;
//                 if(k==0){
//                     l = n-p.second-1+(q*n);
//                     ans = min(ans,l); 
//                 }
//                 else if(m.find(k)!=m.end()){
//                     l= n-p.second-1+m[k]+1+(q*n);
//                     ans = min(ans,l); 
//         }
               
//             }
            
            
//             if(ans==INT_MAX)
//             return -1;
                
//             return ans;
//         }
//         right=0;
//         while(left>right && left<nums.size()){
//             //cout<<"isme aaya h ";
//             curr+=nums[right];
//             if(curr>target){
//                 while(curr>target && left<nums.size()){
//                     curr-=nums[left];
//                     left++;
//                 }
//             }
//             if(curr==target){
//                 ans = min(ans,n-left+right+1);
//                 curr-=nums[left];
//                 left++;
//             }
//             right++;
//         }
//         if(ans==INT_MAX) return -1;
//         return ans;
        unordered_map<long long,int> m;
        int ans=INT_MAX;
        long long sum=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i]==target) return 1;
            //cout<<sum<<" ";
            m[sum]=i;
        }
        m[0]=-1;
        long long curr,diff,bck;
        int ind,qt,rem;
        for(auto k:m){
            curr=k.first;
            ind = k.second;
                    if(curr==target){
                        ans = min(ans,ind+1);
                        //continue;
                    }
           
            diff = target+curr;
            if(m.find(diff)!=m.end()){
                ans = min(ans,m[diff]-ind);
            }
           bck = sum-curr;//7.....49...
           if(bck<=target){
            bck = target-bck;
           qt = (bck/sum);
           rem = bck%sum;
             if(m.find(rem)!=m.end()){
                 ind = (n-ind-1+m[rem]+1+(qt*n));
                 ans = min(ans,ind);
             }
               }
            
        }
        
        
        if(ans==INT_MAX) return -1;
        return ans;
    }
};