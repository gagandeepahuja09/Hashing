class RangeModule {
public:
    set<pair<int, int>> s;
    RangeModule() {}
    
    void addRange(int left, int right) {
        auto it = s.upper_bound({ left, right });
        if(it != s.begin() && (--it) -> second < left) {
            it++;
        }
        while(it != s.end() && it -> first <= right) {
            left = min(left, it -> first);
            right = max(right, it -> second);
            it = s.erase(it);
        }
        s.insert({ left, right });
    }
    
    bool queryRange(int left, int right) {
        auto it = s.upper_bound({ left, INT_MAX });
        return it != s.begin() && right <= (--it) -> second;
    }
    
    void removeRange(int left, int right) {
        auto it = s.upper_bound({ left, right });
        if(it != s.begin() && left >= (--it) -> second)
            ++it;
        while(it != s.end() && it -> first < right) {
            if(it -> first < left) {
                s.insert({ it -> first, left });
            }
            if(it -> second > right) {
                s.insert({ right, it -> second });
            }
            it = s.erase(it);
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
