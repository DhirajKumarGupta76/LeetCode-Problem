class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> start(26, n);
        vector<int> end(26, -1);
        vector<bool> isValid(26, true);

        // Find first and last occurrence of every character
        for (int i = 0; i < n; i++) {

            int c = s[i] - 'a';

            start[c] = min(start[c], i);
            end[c] = i;
        }

        // Check every character
        for (int c = 0; c < 26; c++) {

            // Character does not exist
            if (end[c] == -1)
                continue;

            // Check the complete range of this character
            for (int i = start[c]; i <= end[c]; i++) {

                int x = s[i] - 'a';

                // This character occurs before start[c]
                if (start[x] < start[c]) {
                    isValid[c] = false;
                    break;
                }

                // Extend the ending position
                end[c] = max(end[c], end[x]);
            }
        }

        vector<string> result;

        // Keep track of the starting position
        // of the last selected substring
        int lastTakenStart = INT_MAX;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            int c = s[i] - 'a';

            // Invalid substring
            if (!isValid[c])
                continue;

            // i must be the starting position of this substring
            // and it should not overlap with previous selection
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