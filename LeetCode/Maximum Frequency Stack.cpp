class FreqStack {
public:
    int maxFreq;
    unordered_map<int, int> count;
    unordered_map<int, stack<int>> freqele;
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int x) {
        maxFreq = max(maxFreq, ++count[x]);
        freqele[count[x]].push(x);
    }
    
    int pop() {
        int ret = freqele[maxFreq].top();
        count[ret]--;
        freqele[maxFreq].pop();
        if(freqele[maxFreq].size() == 0) {
            maxFreq = max(--maxFreq, 0);
        }
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
