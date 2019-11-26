class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> mp;
        int area = 0, X1 = INT_MAX, Y1 = INT_MAX, X2 = INT_MIN, Y2 = INT_MIN;
        for(auto v : rectangles) {
            int x1 = v[0], y1 = v[1], x2 = v[2], y2 = v[3];
            X1 = min(X1, x1); Y1 = min(Y1, y1);
            X2 = max(X2, x2); Y2 = max(Y2, y2);
            mp[{ x1, y1 }]++; mp[{ x1, y2 }]++; mp[{ x2, y1 }]++; mp[{ x2, y2 }]++;
            area += (x2 - x1) * (y2 - y1);
        }
        int c = 0, c1 = 0, c2 = 0;
        for(auto m : mp) {
            if(m.second == 1) {
                c1++;
            }
            else if(m.second % 2 == 0)
                c2++;
            c++;
        }
        return (mp[{ X1, Y1 }] == 1 && mp[{ X2, Y1 }] == 1 && mp[{ X1, Y2 }] == 1 && mp[{ X2, Y2 }] == 1 && c1 == 4 && c2 + c1 == c && area == (X2 - X1) * (Y2 - Y1));
    }
};
