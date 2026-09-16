class Solution {
public:
    long long power(long long a, long long b, long long MOD) {

        long long ans = 1;

        while (b > 0) {

            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b /= 2;
        }

        return ans;
    }

    int numberOfSets(int n, int k) {

        const long long MOD = 1e9 + 7;

        // Required:
        // C(n + k - 1, 2 * k)
        int N = n + k - 1;
        int R = 2 * k;

        // factorial[i] = i!
        vector<long long> fact(N + 1, 1);

        for (int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        // C(N, R) = N! / (R! * (N-R)!)
        //
        // Division modulo MOD:
        // a / b = a * b^(MOD-2) % MOD
        long long ans = fact[N];

        ans = ans * power(fact[R], MOD - 2, MOD) % MOD;

        ans = ans * power(fact[N - R], MOD - 2, MOD) % MOD;

        return ans;
    }
};