class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> mp;
        for(int i = 0; i < hand.size(); i++) {
            mp[hand[i]]++;    
        }
        while(!mp.empty()) {
            int n = mp.begin() -> first;
            for(int i = 0; i < W; i++) {
                if(mp.find(n + i) == mp.end()) {
                    return false;
                }
                mp[n + i]--;
                if(mp[n + i] == 0) {
                    mp.erase(n + i);
                }
            }
        }
        return true;
    }
};
