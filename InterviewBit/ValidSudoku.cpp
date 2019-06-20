int Solution::isValidSudoku(const vector<string> &A) {
    int row[10][10];
    memset(row, 0, sizeof row);
    int col[10][10];
    memset(col, 0, sizeof col);
    int square[3][3][10];
    memset(square, 0, sizeof square);
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            if(A[i][j] == '.')
                continue;
            int num = A[i][j] - '0';
            if(row[i][num] == 1 || col[j][num] == 1 || square[i / 3][j / 3][num] == 1) {
                return false;    
            }
            row[i][num] = 1;
            col[j][num] = 1;
            square[i / 3][j / 3][num] = 1;
        }
    }
    return true;
}

