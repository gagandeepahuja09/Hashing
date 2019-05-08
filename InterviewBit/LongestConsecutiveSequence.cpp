/*
Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example: Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

int Solution::longestConsecutive(const vector<int> &A) {
    map<int, int> mp;
    for(int i = 0; i < A.size(); i++) {
        mp[A[i]]++;
    }
    int maxCons = 0;
    for(int i = 0; i < A.size(); i++) {
        if(!mp[A[i] - 1]) {
            int cnt = 1;
            int x = A[i] + 1;
            while(mp[x]) {
                x++;
                cnt++;
            }
            maxCons = max(maxCons, cnt);
        }
    }
    return maxCons;
}

