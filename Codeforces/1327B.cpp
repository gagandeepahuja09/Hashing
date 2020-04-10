    #include <bits/stdc++.h>
    using namespace std;
     
    #define ll long long int
     
    int main() {
        int t;
        cin >> t;
        while(t--) {
            ll n;
            cin >> n;
            vector<int> kingdom(n + 1, 0);
            vector<int> taken(n + 1, 0);
            for(int i = 0; i < n; i++) {
                ll k, x;
                cin >> k;
                for(int j = 0; j < k; j++) {
                    cin >> x;
                    if(!kingdom[x] &&!taken[i + 1]) {
                        kingdom[x] = 1;
                        taken[i + 1] = 1;
                    }
                }
            }
            int x = -1, y = -1;
            for(int i = 1; i <= n; i++) {
                if(!taken[i])
                    x = i;
                if(!kingdom[i])
                    y = i;
            }
            if(x == -1 || y == -1)
                cout << "OPTIMAL" << endl;
            else {
                cout << "IMPROVE" << endl;
                cout << x << " " << y << endl;
            }
        }
    }
