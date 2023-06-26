class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long sum=0;
        int n = costs.size();
        priority_queue<int,vector<int>,greater<int>> left,right;
        int low=0,high=n-1;
        while(low<candidates && low<n){
            left.push(costs[low]);
            low++;
        }
       
        while(high>=n-candidates && high>=low && high>=0){
            right.push(costs[high]);
            high--;
        }
        int j,p;
        int flag=0;
        while(k>0){
                if(low>high){
                       flag=1;
                        break;
                    }
               j = left.top();
               p = right.top();
                if(j<=p){
                        sum+=j;
                        left.pop();
                        left.push(costs[low]);
                        low++;
                }
                else{
                      sum+=p;
                        right.pop();
                        right.push(costs[high]);
                        high--;
                }
            
            k--;
        }
        if(flag==1){
             while(left.size()>0){
                            p = left.top();
                            right.push(p);
                            left.pop();
                        }
            while(k>0){
                sum+=right.top();
                right.pop();
                k--;
            }
        }
        return sum;
    }
};