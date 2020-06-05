#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define read(a)  for(int i = 0; i < n; i++) cin >> a[i];
#define print(a)  for(int i = 0; i < n; i++) cout << a[i] << " ";
#define pb push_back
#define pql priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define pqlv priority_queue<vi>
#define pqsv priority_queue<vi, vvi, greater<vi>>
#define endl '\n'
#define N 1234567
#define MOD 1000000007

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi x(n), y(n);
        map<vi, set<int>> mp;
        for(int i = 0; i < n; i++)  cin >> x[i] >> y[i];
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int a = -(x[j] - x[i]), b = (y[j] - y[i]);
                int c = (a * y[i] + b * x[i]);
                int g = __gcd(abs(a), __gcd(abs(b), abs(c)));
                a /= g; b /= g; c /= g;
                if(a < 0) {
                    a *= -1; b *= -1; c *= -1;
                }
                if(b < 0) {
                    a *= -1; b *= -1; c *= -1;
                }
                mp[{ a, b}].insert(c);
            }
        }
        int ans = 0, total = 0;
        for(auto& i : mp) {
            int sz = i.second.size();
            total += sz;
            ans -= (sz * (sz - 1) / 2);
        }
        ans += ((total) * (total - 1) / 2);
        cout << ans << endl;
    }
	return 0;
}
