/*Given two array of integers A and B of size N and M respectively.

The goal is to select some continuous interval in A such that there are exactly
B[0] elements with value 1, B[1] elements with value 2 and so on
ending with B[m-1] elements with value m.

However, it is not always possible to select such an interval form the given array therefore it is allowed
to remove some elements from A in order to achieve the goal.

Find and return the minimum number of elements to be removed from A in order to achieve the goal.
If it is not possible to achieve the goal return -1 instead.*/

int Solution::solve(vector<int> &A, vector<int> &B) {
    int m = B.size();
    vector<int> cnt(m, 0);
    int mn = INT_MAX, start = 0;
    int need, sum = 0;
    for(int i = 0; i < B.size(); i++) {
        sum += B[i];
    }
    need = sum;
    
    for(int i = 0, j = 0; ; ) {
        if(j < A.size() && need > 0) {
            int num = A[j] - 1;
            if(cnt[num] < B[num]) {
                need--;
            }
            cnt[num]++;
            j++;
        }
        else if(i < A.size() && need == 0) {
            mn = min(mn, j - i - sum);
            int num = A[i] - 1;
            cnt[num]--;
            if(cnt[num] < B[num]) {
                need++;
            }
            i++;
        }
        else
            break;
    }
    return mn == INT_MAX ? -1 : mn;
}

