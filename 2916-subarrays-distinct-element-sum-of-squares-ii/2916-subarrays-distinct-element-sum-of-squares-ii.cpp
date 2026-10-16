
class Solution {
    using ll = long long;
    static constexpr ll MOD = 1000000007LL;

    struct Node {
        ll sum = 0;
        ll sqSum = 0;
        ll lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int node, int l, int r, ll val) {
        ll len = r - l + 1LL;
        val %= MOD;

        // (x + val)^2 = x^2 + 2*x*val + val^2
        seg[node].sqSum =
            (seg[node].sqSum
             + 2LL * val % MOD * seg[node].sum % MOD
             + len % MOD * val % MOD * val % MOD) % MOD;

        seg[node].sum =
            (seg[node].sum + len % MOD * val % MOD) % MOD;

        seg[node].lazy = (seg[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r) return;

        int mid = l + (r - l) / 2;
        ll val = seg[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, ll val) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        seg[node].sum =
            (seg[node * 2].sum + seg[node * 2 + 1].sum) % MOD;

        seg[node].sqSum =
            (seg[node * 2].sqSum + seg[node * 2 + 1].sqSum) % MOD;
    }

    ll querySquares(int node, int l, int r,
                    int ql, int qr) {
        if (ql > r || qr < l) return 0;

        if (ql <= l && r <= qr)
            return seg[node].sqSum;

        push(node, l, r);

        int mid = l + (r - l) / 2;

        return (querySquares(node * 2, l, mid, ql, qr)
              + querySquares(node * 2 + 1, mid + 1, r, ql, qr))
              % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n + 5, Node());

        unordered_map<int, int> last;
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int left = last.count(nums[i]) ? last[nums[i]] + 1 : 0;

            // Every subarray ending at i:
            // increase distinct count for starts in [left, i].
            update(1, 0, n - 1, left, i, 1);

            // Add the squared distinct counts of all subarrays
            // ending at i.
            ans = (ans + querySquares(1, 0, n - 1, 0, i)) % MOD;

            last[nums[i]] = i;
        }

        return (int)ans;
    }
};
