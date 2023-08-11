class Solution {
public:
    int row,col;
    set<pair<int,int>> r;
    pair<int,int> p;
    Solution(int m, int n) {
        row=m;
        col=n;
    }
    
    vector<int> flip() {
        p.first =rand()%row;
        p.second = rand()%col;
        while(r.find(p)!=r.end()){
             p.first =rand()%row;
        p.second = rand()%col;
        }
       r.insert(p);
        return {p.first,p.second};
    }
    
    void reset() {
        r.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */