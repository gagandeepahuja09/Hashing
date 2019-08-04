class SnapshotArray {
public:
    int cnt = 0, ind = -1, value = 0;
    map<pair<int, int>, int> mp;
    vector<int> v;
    
    SnapshotArray(int n) {
        mp.clear();
        ind = -1;
        value = 0;
        v.resize(n, 0);
    }
    
    void set(int idx, int val) {
        v[idx] = val;
        mp[{ idx, cnt }] = val;
    }
    
    int snap() {
        cnt++;
        return cnt - 1;
    }
    
    int get(int index, int snap_id) {
        while(mp.find({ index, snap_id }) == mp.end() && snap_id >= 0)
            snap_id--;
        return mp[{index, snap_id }];
    }
};
