/*Input:
N = 5, D = [[1, 2, 10], [2, 3, 20], [2, 5, 25]]

Return: [10, 55, 45, 25, 25]*/

vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> v(A, 0);
    for(int i = 0; i < B.size(); i++) {
        int l = B[i][0] - 1, r = B[i][1] - 1;
        v[l] += B[i][2];
        if(r + 1 < A)
            v[r + 1] -= B[i][2];
    }
    for(int i = 1; i < A; i++) {
        v[i] += v[i - 1];
    }
    return v;
}

