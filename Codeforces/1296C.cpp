#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    int sum = 0;
	    map<pair<int, int>, int> mp;
	    mp[{ 0, 0 }] = 1;
	    int x = 0, y = 0;
	    int ans = INT_MAX, l, r;
	    for(int i = 0; i < n; i++) {
	        if(s[i] == 'L') x--;
	        else if(s[i] == 'R')    x++;
	        else if(s[i] == 'U')    y++;
	        else    y--;
	        if(mp[{ x, y }]) {
	            int curr = i + 2 - mp[{ x, y }];
	            if(curr < ans) {
	                ans = curr;
	                l = mp[{ x, y }];
	                r = i + 1;
	            }    
	        }
	        mp[{ x, y }] = i + 2;
	    }
	    if(ans == INT_MAX)
	        cout << -1;
	    else
	        cout << l << " " << r;
	    cout << endl; 
	}
	return 0;
}
