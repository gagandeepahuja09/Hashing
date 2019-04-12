string Solution::fractionToDecimal(int A, int B) {
    if(!A)
        return "0";
    long n = A, d = B;
    string res = "";
    if(n < 0 ^ d < 0)
        res += '-';
    n = abs(n);
    d = abs(d);
    res += to_string(n / d);
    long rem = n % d;
    if(!rem)
        return res;
    res += '.';
    unordered_map<int, int> mp;
    while(rem) {
        if(mp.find(rem) != mp.end()) {
            res.insert(mp[rem], 1, '(');
            res.push_back(')');
            break;
        }
        mp[rem] = res.size();
        rem *= 10;
        res += (rem / d + '0');
        rem %= d;
    }
    return res;
}

