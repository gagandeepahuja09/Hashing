class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> mp;
    unordered_map<string, int> str;
    MapSum() {
        mp.clear(); str.clear();
    }
    
    void insert(string key, int val) {
        string s;
        bool flag = (str[key] != 0);
        for(int i = 0; i < key.size(); i++) {
            s += key[i];
            mp[s] += val;
            if(flag)
                mp[s] -= str[key];
        }
        str[key] = val;
    }
    
    int sum(string prefix) {
        return mp[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
