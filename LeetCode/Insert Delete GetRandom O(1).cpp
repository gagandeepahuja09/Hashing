class RandomizedSet {
public:
    int size;
    unordered_map<int, int> mp;
    vector<int> v;
    /** Initialize your data structure here. */
    RandomizedSet() {
        v.clear();
        mp.clear();
        size = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val))
            return false;
        mp[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!mp.count(val))
            return false;
        mp[v.back()] = mp[val];
        v[mp[val]] = v.back();
        v.pop_back();
        mp.erase(val);
        size--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int rn = rand() % v.size();
        return v[rn];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
