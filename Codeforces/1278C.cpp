#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define read(a)  for(int i = 0; i < n; i++) cin >> a[i];
#define print(a)  for(int i = 0; i < n; i++) cout << a[i] << " ";
#define pb push_back
#define ins insert
#define pql priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define pqlv priority_queue<vi>
#define pqsv priority_queue<vi, vvi, greater<vi>>
#define endl '\n'

signed main() {
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for(int i = 0; i < 2 * n; i++)
            cin >> a[i];
        map<int, int> mp;
        mp[0] = n;
        int curr = 0;
        int diff = count(a.begin(), a.end(), 1) - count(a.begin(), a.end(), 2);
        for(int i = n; i < 2 * n; i++) {
            if(a[i] == 1)   curr++;
            else    curr--;
            if(!mp.count(curr)) {
                mp[curr] = i + 1;
            }
        }
        curr = 0;
        int ans = INT_MAX;
        if(!diff)
            ans = 0;
        if(mp.count(diff)) {
            ans = min(ans, mp[diff] - n);
        }
        for(int i = n - 1; i >= 0; i--) {
            if(a[i] == 1)   curr++;
            else    curr--;
            if(mp.count(diff - curr)) {
                ans  = min(ans, mp[diff - curr] - i);
            }
        }
        cout << ans << endl;
    }
	return 0;
}
