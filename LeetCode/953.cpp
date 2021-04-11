class Solution {
public:
    bool checkOrder(string early, string late, vector<int>& pos) {
        int lenE = early.size(), lenL = late.size(), k = 0;
        for (k = 0; k < min(lenE, lenL); k++) {
            if (pos[early[k] - 'a'] > pos[late[k] - 'a']) {
                return false;
            } else if (pos[early[k] - 'a'] < pos[late[k] - 'a']) {
                return true;
            }
        }
        return !(lenE > lenL && k == min(lenE, lenL));
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> pos(26, 0);
        for (int i = 0; i < order.size(); i++) {
            pos[order[i] - 'a'] = i; 
        }
        // Rather than checking if each pair is sorted, just check if adjacent pairs are sorted
        for (int i = 0; i < words.size() - 1; i++) {
                if (!checkOrder(words[i], words[i + 1], pos)) {
                    return false;
                }
        }
        return true;
    }
};
