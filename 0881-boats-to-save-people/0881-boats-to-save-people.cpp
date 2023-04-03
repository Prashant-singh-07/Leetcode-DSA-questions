class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans=0;
        // for(int i=0;i<people.size();i++){
        //     if(i+1<people.size()){
        //         if(people[i]+people[i+1]<=limit){
        //             i++;
        //         }
        //     }
        //     ans++;
        // }
           int left=0;
        int n = people.size();
        int right=n-1;
        while(left<right){
            if(people[left]+people[right]<=limit){
                left++;
                right--;
            }
            else{
                right--;
            }
            ans++;
        }
        if(left==right) ans++;
        return ans;
    }
};