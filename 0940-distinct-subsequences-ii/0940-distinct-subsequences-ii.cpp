class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        // dp = number of distinct subsequences including empty ""
        long long dp = 1;

        // last[i] = dp value before the previous occurrence of character i
        vector<long long> last(26, 0);

        for (char ch : s) {
            int idx = ch - 'a';

            long long newdp = (2 * dp - last[idx] + MOD) % MOD;

            // Store old dp for this character
            last[idx] = dp;

            dp = newdp;
        }

        // Remove empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};