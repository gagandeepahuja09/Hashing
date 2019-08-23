#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> roll(n + 1, 0);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            roll[0]++;
            if(x >= n)
                continue;
            roll[x]--;    
        }
        for(int i = 1; i < n; i++) {
            roll[i] += roll[i - 1];
        }
        for(int i = 0; i < s.size(); i++) {
            s[i] = (char)(((s[i] - 'a' + roll[i]) % 26) + 'a'); 
        }
        cout << s << endl;
    }
	return 0;
}
