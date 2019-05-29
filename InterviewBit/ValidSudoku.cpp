int Solution::isValidSudoku(const vector<string> &A) {
    vector<vector<int>> row(10, vector<int>(10, 0));
    vector<vector<int>> col(10, vector<int>(10, 0));
    vector<vector<vector<int>>> square(3, vector<vector<int>>(3, vector<int>(10, 0)));
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            if(A[i][j] != '.') {
                int val = A[i][j] - '0';
                if(val < 0 || val > 10 || row[val][i] || col[val][j] || square[i / 3][j / 3][val])
                    return false;
                row[val][i] = 1;
                col[val][j] = 1;
                square[i / 3][j / 3][val] = 1;
            }
        }
    }
    return true;
}

