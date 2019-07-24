string Solution::fractionToDecimal(int A, int B) {
    if(!A)
        return "0";
    string ret = "";
    if(A > 0 ^ B > 0)
        ret += '-';
    long num  = labs(A), den = labs(B);
    long val = num % den;
    ret += to_string(num / den);
    if(!val) {
        return ret;
    }
    ret += '.';
    unordered_map<int, int> mp;
    while(val) {
        if(mp[val]) {
            ret.insert(mp[val], "(");
            ret += ')';
            break;
        }
        mp[val] = ret.size();
        val *= 10;
        ret += to_string(val / den);
        val %= den;
    }
    return ret;
}
