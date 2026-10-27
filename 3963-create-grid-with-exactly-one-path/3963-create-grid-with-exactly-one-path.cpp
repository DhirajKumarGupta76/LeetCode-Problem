
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> mat(m, string(n, '#'));

        // Make the first row free
        for (int j = 0; j < n; j++) {
            mat[0][j] = '.';
        }

        // Make the last column free
        for (int i = 1; i < m; i++) {
            mat[i][n - 1] = '.';
        }

        return mat;
    }
};

