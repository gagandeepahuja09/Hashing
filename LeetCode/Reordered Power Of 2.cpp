class Solution {
public:
    long counter(int N) {
        long ans = 0;
        while(N) {
            ans += pow(10, N % 10);    
            N /= 10;
        }
        return ans;
    }
    
    bool reorderedPowerOf2(int N) {
        // Similar to string anagrams problem
        // We only need to check with 32 numbers
        long compare = counter(N);
        for(int i = 0; i < 32; i++) {
            if(counter(1 << i) == compare)
                return true;
        }
        return false;
    }
};
