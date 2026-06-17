class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;  // no primes exist below 2

        vector<bool> isPrime(n, true);  // indices 0..n-1
        isPrime[0] = isPrime[1] = false;

        for (long long p = 2; p * p < n; p++) {
            if (isPrime[p]) {
                for (long long multiple = p * p; multiple < n; multiple += p) {
                    isPrime[multiple] = false;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }
};
