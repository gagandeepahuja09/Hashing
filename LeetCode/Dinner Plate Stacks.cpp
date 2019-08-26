class DinnerPlates {
public:
    int c;
    map<int, vector<int>> m;
    set<int> st;
    DinnerPlates(int capacity) {
        c = capacity;
    }
    
    void push(int val) {
        if(!st.size())
            st.insert(m.size());
        m[*st.begin()].push_back(val);
        if(m[*st.begin()].size() == c)
            st.erase(st.begin());
    }
    
    int pop() {
        if(!m.size())
            return -1;
        return popAtStack(m.rbegin() -> first);
    }
    
    int popAtStack(int index) {
        if(!m[index].size())
            return -1;
        int val = m[index].back();
        m[index].pop_back();
        st.insert(index);
        if(m[index].size() == 0)
            m.erase(index);
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
