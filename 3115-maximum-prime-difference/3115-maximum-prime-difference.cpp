class Solution {
public:
    bool isPrime(int a) {

        if (a == 1)
            return false;
        for (int i = 2; i <= sqrt(a); i++) {
            if (a % i == 0) {
                return false;
            }
        }

        return true;
    }

    void primes(int n, set<int>& st) {}
    unordered_set<int> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        unordered_set<int> primes;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i])
                primes.insert(i);
        }

        return primes;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int first = -1;
        int last = -1;
        unordered_set<int> st = sieve(100);
        
        for (int i = 0; i < n; i++) {
            if (st.find(nums[i])!=st.end()) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }

        return last - first;
    }
};