class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<string, vector<pair<int, int>>> mp;
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                int diagonal = ((points[i][1] - points[j][1]) * (points[i][1] - points[j][1])) + ((points[i][0] - points[j][0]) * (points[i][0] - points[j][0]));
                double cx = (double)(points[i][0] + points[j][0]) / 2;
                double cy = (double)(points[i][1] + points[j][1]) / 2;
                string key = to_string(diagonal) + "_" + to_string(cx) + "_" + to_string(cy);
                mp[key].push_back({ i , j });
            }
        }
        
        double ans = DBL_MAX;
        for(auto it : mp) {
            vector<pair<int, int>> v = it.second;
            for(int i = 0; i < v.size(); i++) {
                for(int j = i + 1; j < v.size(); j++) {
                    int p1 = v[i].first, p2 = v[i].second, p3 = v[j].first;
                    double len1 = (double)(points[p1][1] - points[p3][1]) * (points[p1][1] - points[p3][1]) + (double)(points[p1][0] - points[p3][0]) * (points[p1][0] - points[p3][0]);
                    double len2 = (double)(points[p3][1] - points[p2][1]) * (points[p3][1] - points[p2][1]) + (double)(points[p3][0] - points[p2][0]) * (points[p3][0] - points[p2][0]);
                    ans = min(ans, sqrt(len1) * sqrt(len2));
                }
            }
        }
        return ans == DBL_MAX ? 0 : ans;
    }
};
