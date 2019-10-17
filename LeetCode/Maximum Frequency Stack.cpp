class FreqStack {
public:
    unordered_map<int, stack<int>> freqMap;
    unordered_map<int, int> cnt;
    int maxFreq;
    FreqStack() {
        freqMap.clear();
        cnt.clear();
        maxFreq = 0;
    }
    
    void push(int x) {
        cnt[x]++;
        freqMap[cnt[x]].push(x);
        maxFreq = max(maxFreq, cnt[x]);
    }
    
    int pop() {
        int t = freqMap[maxFreq].top();
        freqMap[maxFreq].pop();
        if(freqMap[cnt[t]].size() == 0)
            maxFreq--;
        cnt[t]--;
        return t;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
