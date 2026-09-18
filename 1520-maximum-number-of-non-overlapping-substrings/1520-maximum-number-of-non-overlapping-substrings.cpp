class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> start(26, -1);
        vector<int> end(26, 0);
        vector<bool> isValid(26, true);

        // Find first and last occurrence
        for (int i = 0; i < n; i++) {

            int c = s[i] - 'a';

            // First occurrence
            if (start[c] == -1) {
                start[c] = i;
            }

            // Last occurrence
            end[c] = i;
        }

        // Check whether each character can form a valid substring
        for (int c = 0; c < 26; c++) {

            // Character is not present
            if (start[c] == -1)
                continue;

            for (int i = start[c]; i <= end[c]; i++) {

                int x = s[i] - 'a';

                // Character occurs before start[c]
                if (start[x] < start[c]) {
                    isValid[c] = false;
                    break;
                }

                // Expand the ending position
                end[c] = max(end[c], end[x]);
            }
        }

        vector<string> result;

        int lastTakenStart = INT_MAX;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            int c = s[i] - 'a';

            if (!isValid[c])
                continue;

            // i is the starting position
            // and substring does not overlap
            if (i == start[c] && end[c] < lastTakenStart) {

                result.push_back(
                    s.substr(i, end[c] - i + 1)
                );

                lastTakenStart = i;
            }
        }

        return result;
    }
};