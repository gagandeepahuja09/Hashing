class Solution {
public:
    string toHexspeak(string num) {
        string s;
        vector<string> v = { "O", "I", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
        long long int n = stoll(num);
        while(n) {
            int x = n % 16;
            s += v[x];
            n /= 16;
        }
        bool f = true;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '2' && s[i] <= '9')
                f = false;
        }
        if(!f)
            return "ERROR";
        reverse(s.begin(), s.end());
        return s;
    }
};
