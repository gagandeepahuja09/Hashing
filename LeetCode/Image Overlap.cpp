class Solution {
public:
    /* int compare(vector<vector<int>>& A, vector<vector<int>>& B, int x, int y) {
        int ans = 0, n = A.size();
        for(int i = 0; i < n && i + x < n; i++) {
           for(int j = 0; j < n && j + y < n; j++) {
               ans += (A[i + x][j + y] * B[i][j]);
           }
        }
        return ans;
    } 
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                res = max(res, compare(A, B, i, j));
                res = max(res, compare(B, A, i, j));
            }
        }
        return res;
    }
    */
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> la, lb;
        int n = A.size(), res = 0;
        unordered_map<int, int> count;
        for(int i = 0; i < n * n; i++)
            if(A[i / n][i % n] == 1)
                la.push_back(i / n * 100 + i % n);
        for(int i = 0; i < n * n; i++)
            if(B[i / n][i % n] == 1)
                lb.push_back(i / n * 100 + i % n);
        for(int i : la) {
            for(int j : lb) {
                res = max(res, ++count[i - j]);
            }
        }
        return res;
    }
};
