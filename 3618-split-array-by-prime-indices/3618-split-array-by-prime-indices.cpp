class Solution {
public:
    vector<bool> sieve(int n) {
        if (n < 0)
            return {};

        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        if (n >= 1)
            isPrime[1] = false;

        for (int i = 2; 1LL * i * i <= n; i += 1) {
            if (isPrime[i]) {
                long long j = 1LL * i * i;
                while (j <= n) {
                    isPrime[j] = false;
                    j += i;
                }
            }
        }

        return isPrime;
    }

    long long splitArray(vector<int>& nums) {
        int n = nums.size();

        vector<bool>isPrime = sieve(n);
        long long sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            if(isPrime[i]){
                sum1=(long long)sum1 + nums[i];
            }else{
                sum2=(long long)sum2 + nums[i];
            }
        }

        return abs(sum1-sum2);
    }
};