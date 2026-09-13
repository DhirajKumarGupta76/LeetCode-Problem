#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();
        int ans = 0;

        // Try every possible vertical shift
        for (int dr = -(n - 1); dr <= n - 1; dr++) {

            // Try every possible horizontal shift
            for (int dc = -(n - 1); dc <= n - 1; dc++) {

                int overlap = 0;

                // Check every cell of img1
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {

                        // New position of img1[i][j]
                        // after applying the translation
                        int ni = i + dr;
                        int nj = j + dc;

                        // Check whether translated position
                        // is inside the matrix
                        if (ni >= 0 && ni < n &&
                            nj >= 0 && nj < n) {

                            // If both images have 1,
                            // then we get an overlap
                            if (img1[i][j] == 1 &&
                                img2[ni][nj] == 1) {
                                overlap++;
                            }
                        }
                    }
                }

                // Store maximum overlap
                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};