class Solution {
public:
    long counter(int N) {
        long res = 0;
        while(N) {
            res += pow(10, N % 10);
            N /= 10;
        }
        return res;
    }
    
    bool reorderedPowerOf2(int N) {
        long cmp = counter(N);
        for(int i = 0; i < 32; i++) {
            long curr = counter(1 << i);
            if(curr == cmp)
                return 1;
        }
        return 0;
    }
};
