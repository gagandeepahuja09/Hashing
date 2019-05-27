vector<int> Solution::solve(int A, vector<vector<int> > &B, vector<vector<int> > &C) {
    unordered_map<int, int> row, col, diag1, diag2;
    set<pair<int, int>> s;
    for(int i = 0; i < B.size(); i++) {
        int r = B[i][0], c = B[i][1];
        s.insert(make_pair(r, c));
        row[r]++;
        col[c]++; 
        diag1[r + c]++;
        diag2[r - c]++;
    }
    vector<int> ret;
    for(int i = 0; i < C.size(); i++) {
        int r = C[i][0], c = C[i][1];
        if(row[r] > 0 || col[c] > 0 || diag1[r + c] > 0 || diag2[r - c] > 0) {
            ret.push_back(1);
            for(int j = -1; j <= 1; j++) {
                for(int k = -1; k <= 1; k++) {
                    if(r + j < A && r + j >= 0 && c + k < A && c + k >= 0 
                    && s.find(make_pair(r + j, c + k)) != s.end()) {
                        s.erase(make_pair(r + j, c + k));
                        row[r + j]--; 
                        col[c + k]--; 
                        diag1[r + j + c + k]--; 
                        diag2[r + j - c - k]--;
                    }
                }
            }
        }
        else
            ret.push_back(0);
    }
    return ret;
}

