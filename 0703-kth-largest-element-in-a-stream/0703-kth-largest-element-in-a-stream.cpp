class KthLargest {
public:
priority_queue<int,vector<int>,greater<int>> pq;
int s;
int k;
bool temp=0;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        s=n;
        while(s>k){
            s--;
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        s++;
        if(s>k){
            pq.pop();
        }
        return pq.top();
    }
};
