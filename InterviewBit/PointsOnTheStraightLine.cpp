int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_map<double, int> mp;
    if(!A.size())
        return 0;
    int mx = 1;
    int currMax = 0;
    int duplicate, vertical;
    for(int i=0; i<A.size(); i++) {
        currMax = 0, duplicate = 1, vertical = 0;
        double slope = 0.0;
        for(int j=i+1; j<A.size(); j++) {
            if(A[j] != A[i]) {
                slope = (1.0 * (B[j] - B[i])/(A[j] - A[i]));
                mp[slope]++;
            }
            else {
                if(B[i] == B[j])
                    duplicate++;
                else
                    vertical++;
            }
            currMax = max(currMax, max(vertical, mp[slope]));
        }
        mx = max(mx, currMax + duplicate);
        mp.clear();
    }
    return mx;
}

