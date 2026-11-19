class Solution {
public:
    unordered_map<int, int> dp;

    int helper(int n) {
        if (n == 0) return 0;
        if (dp.count(n)) return dp[n];

        if ((n & (n - 1)) == 0) return dp[n] = 1;

        int p = 1;
        while (p < n) p <<= 1;

        int add = 1 + helper(p - n);         
        int sub = 1 + helper(n - (p >> 1)); 

        return dp[n] = min(add, sub);
    }

    int minOperations(int n) {
        return helper(n);
    }
};
