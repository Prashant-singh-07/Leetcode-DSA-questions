class SnapshotArray {
public:
    int snapCount=0;
   vector<vector<pair<int,int>>> m;
    SnapshotArray(int length) {
        
        m = vector<vector<pair<int,int>>>(length);
    }
    
    void set(int index, int val) {
       if (!m[index].empty() && m[index].back().first == snapCount)
            m[index].back().second = val;
        else
            m[index].push_back({snapCount, val});
    }
    
    int snap() {
        snapCount++;
        return snapCount-1;
    }
    
    int get(int index, int snap_id) {
        
        int idx = upper_bound(m[index].begin(), m[index].end(), make_pair(snap_id,INT_MAX)) - m[index].begin();
        if (idx == 0) return 0;
        return m[index][idx - 1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */