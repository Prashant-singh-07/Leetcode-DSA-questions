class MedianFinder {
public:
    priority_queue<int> low;
    priority_queue<int,vector<int>,greater<int>> high;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(low.size()==0) {
            low.push(num);
        }
        else{
            if(num<=low.top()){
                low.push(num);
            }
            else{
                if(high.size()>0) high.push(num);
                else{
                    low.push(num);
                }
            }
        }
        int j,k;
        j = high.size();
         k=low.size();
          if(j>k){
              low.push(high.top());
              high.pop();
          }
        else if(k>j && k-j>1){
            high.push(low.top());
            low.pop();
        }
        
    }
    
    double findMedian() {
        int j,k;
        j = high.size();
        k=low.size();
        if((j+k) %2!=0) return (double)low.top();
        return ((double)low.top()+(double)high.top())*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */