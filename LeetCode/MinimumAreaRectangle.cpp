class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int, int>> s;
        int mn = INT_MAX;
        for(int i = 0; i < points.size(); i++) {
            s.insert({ points[i][0], points[i][1] });
        }
        for(int i = 0; i < points.size(); i++) {
            for(int j = 0; j < i; j ++) {
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                if(x1 != x2 && y1 != y2 && s.find({ x1, y2}) != s.end() && s.find({ x2, y1 }) != s.end()) {
                    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                    int curr = abs(x2 - x1) * abs(y2 - y1);
                    if(curr > 0)
                        mn = min(mn, curr);
                }
            }
        }
        return mn != INT_MAX ? mn : 0;
    }
};
