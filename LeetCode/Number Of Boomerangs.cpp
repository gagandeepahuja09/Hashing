class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ret = 0;
        for(int i = 0; i < points.size(); i++) {
            unordered_map<int, int> distFreq;
            for(int j = 0; j < points.size(); j++) {
                if(j == i)
                    continue;
                int dist = ((points[i][0] - points[j][0]) * (points[i][0] - points[j][0])) + 
                    ((points[i][1] - points[j][1]) * (points[i][1] - points[j][1]));
                distFreq[dist]++;
            }
            for(auto it : distFreq) {
                ret += ((it.second) * (it.second - 1));
            }
        }
        return ret;
    }
};
