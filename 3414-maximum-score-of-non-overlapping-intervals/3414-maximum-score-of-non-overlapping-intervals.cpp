class Solution {
public:

    struct Node {
        long long score;
        vector<int> ids;
    };

    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<vector<Node>> dp;
    vector<vector<int>> vis;
    vector<int> starts;

    Node solve(vector<vector<int>>& a, int i, int cnt) {

        // We can select at most 4 intervals
        if (i == a.size() || cnt == 4)
            return {0, {}};

        if (vis[i][cnt])
            return dp[i][cnt];

        vis[i][cnt] = 1;

        // -------------------
        // 1. Don't take i
        // -------------------
        Node skip = solve(a, i + 1, cnt);

        // -------------------
        // 2. Take i
        // -------------------

        int end = a[i][1];

        // First interval with start > end
        int next = upper_bound(
            starts.begin(),
            starts.end(),
            end
        ) - starts.begin();

        Node take = solve(a, next, cnt + 1);

        take.score += a[i][2];
        take.ids.push_back(a[i][3]);

        // Since we are selecting intervals in sorted order,
        // ids may not be sorted, so sort them before comparison.
        sort(take.ids.begin(), take.ids.end());

        // Choose the better answer
        if (better(take, skip))
            dp[i][cnt] = take;
        else
            dp[i][cnt] = skip;

        return dp[i][cnt];
    }


    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Add original index
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        // Sort by start, then end
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {

                if (a[0] != b[0])
                    return a[0] < b[0];

                return a[1] < b[1];
            });

        // Store all starting positions
        starts.resize(n);

        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
        }

        dp.resize(n, vector<Node>(5));
        vis.resize(n, vector<int>(5, 0));

        return solve(intervals, 0, 0).ids;
    }
};