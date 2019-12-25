class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> reqCap(1001, 0);
        for(auto t : trips) {
            reqCap[t[1]] += t[0];
            reqCap[t[2]] -= t[0];
        }
        int currCap = 0;
        for(int i = 0; i <= 1000; i++) {
            currCap += reqCap[i];
            if(currCap > capacity) {
                return false;
            }
        }
        return true;
    }
}; 
