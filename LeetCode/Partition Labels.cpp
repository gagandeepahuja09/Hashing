class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> pos(26, -1);
        for(int i = 0; i < S.size(); i++) {
            pos[S[i] - 'a'] = i;
        }
        vector<int> ret;
        int maxIdx = -1, lastIdx = 0;
        for(int i = 0; i < S.size(); i++) {
            maxIdx = max(maxIdx, pos[S[i] - 'a']);
            if(maxIdx == i) {
                ret.push_back(maxIdx - lastIdx + 1);
                lastIdx = i + 1;
            }
        }
        return ret;
    }
};
