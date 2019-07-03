class Solution {
public:
    string str(int s1, int s2) {
        return to_string(s1) + '_' + to_string(s2);
    }
    
    double minAreaFreeRect(vector<vector<int>>& p) {
        unordered_set<string> s;
        for(auto x : p) {
            s.insert(str(x[0], x[1]));
        }
        double ans = 0;
        for(int i = 0; i < p.size(); i++) {
            for(int j = 0; j < p.size(); j++) {
                for(int k = j + 1; k < p.size(); k++) {
                    if(i == j || i == k)
                        continue;
                    int x1 = p[i][0], y1 = p[i][1], x2 = p[j][0], y2 = p[j][1], x3 = p[k][0], y3 = p[k][1];
                    if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) != 0) continue;
                    int x4 = (x2 + x3) - x1, y4 = (y2 + y3) - y1;
                    if(s.count(str(x4, y4))) {
                        double w = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
                        double l = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);
                        double area = w * l;
                        if(ans == 0 || area != 0 && area < ans)
                            ans = area;
                    }
                }
            }
        }
        return ans;
    }
};
