
class Solution {
public:
    string convert(string s, int numRows) {

        // Edge case: If only one row or string length
        // is less than or equal to the number of rows
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Create a vector of strings.
        // Each string represents one row.
        vector<string> rows(numRows);

        // Initially, we are moving downward
        int currentRow = 0;
        bool goingDown = false;

        // Traverse every character of the original string
        for (char ch : s) {

            // Add current character to the current row
            rows[currentRow] += ch;

            // Change direction when we reach the first
            // row or the last row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move to the next row
            if (goingDown) {
                currentRow++;
            }
            else {
                currentRow--;
            }
        }

        // Combine all rows into the final answer
        string ans = "";

        for (string row : rows) {
            ans += row;
        }

        return ans;
    }
};
