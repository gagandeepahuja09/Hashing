void Solution::setZeroes(vector<vector<int> > &A) {
    bool firstRow = false, firstCol = false;
    for(int i = 0; i < A[0].size(); i++) {
        if(A[0][i] == 0)
            firstRow = true;
    }
    for(int i = 0; i < A.size(); i++) {
        if(A[i][0] == 0)
            firstCol = true;
    }
    for(int i = 1; i < A.size(); i++) {
        for(int j = 1; j < A[0].size(); j++) {
            if(A[i][j] == 0) {
                A[i][0] = 0; 
                A[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < A.size(); i++) {
        for(int j = 1; j < A[0].size(); j++) {
            if(A[i][0] == 0 || A[0][j] == 0) {
                A[i][j] = 0;
            }
        }
    }
    if(firstRow) {
        for(int i = 0; i < A[0].size(); i++) {
                A[0][i] = 0;
        }
    }
    if(firstCol) {
        for(int i = 0; i < A.size(); i++) {
                A[i][0] = 0;
        }
    }
}

