class SummaryRanges {
public:
    set<int> m;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        m.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int start=-1,end=-1;
        for(auto k:m){
            if(start==-1){
                start=end=k;
            }
            else if(k==end+1){
                end=k;
                ans.pop_back();
            }
            else{
                start=end=k;
            }
            if(start!=-1) ans.push_back({start,end});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */