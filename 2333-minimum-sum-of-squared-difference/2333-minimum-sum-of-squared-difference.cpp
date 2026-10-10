
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<int> diff(n);

        long long total = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        // If all differences can become zero
        if (k >= total) return 0;

        // Binary search for the final maximum difference
        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) need += d - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int level = low;
        long long ans = 0;

        // Reduce every difference above level to level
        for (int d : diff) {
            int reduced = min(d, level);
            ans += 1LL * reduced * reduced;
            k -= max(0, d - level);
        }

        // Use remaining operations to reduce level to level - 1
        for (int d : diff) {
            if (k == 0) break;

            if (d >= level && level > 0) {
                ans -= 1LL * level * level;
                ans += 1LL * (level - 1) * (level - 1);
                k--;
            }
        }

        return ans;
    }
};
