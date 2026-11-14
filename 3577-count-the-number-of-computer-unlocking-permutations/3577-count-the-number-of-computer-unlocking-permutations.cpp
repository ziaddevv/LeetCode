class Solution {
public:
    int countPermutations(vector<int>& cmplx) {

        int n = cmplx.size();
        int mn = *min_element(cmplx.begin(), cmplx.end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cmplx[i] == mn) {
                cnt++;
            }
        }

        if (mn != cmplx[0] || cnt != 1) {
            return 0;
        }

        const int MOD = 1000000007;  

        long long res = 1;
        for (int i = 1; i < n; ++i) {
            res = (res * i) % MOD;
        }

        return (int)res;
    }
};