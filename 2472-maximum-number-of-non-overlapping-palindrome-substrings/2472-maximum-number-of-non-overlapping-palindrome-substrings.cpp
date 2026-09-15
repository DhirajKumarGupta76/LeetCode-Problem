class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;
        int start = 0;

        while (start < n) {

            bool found = false;

            // Check every center
            for (int i = start; i < n; i++) {

                // -------- ODD --------
                int left = i;
                int right = i;

                while (left >= start && right < n &&
                       s[left] == s[right]) {

                    int len = right - left + 1;

                    if (len >= k) {
                        count++;
                        start = right + 1;
                        found = true;
                        break;
                    }

                    left--;
                    right++;
                }

                if (found)
                    break;


                // -------- EVEN --------
                left = i;
                right = i + 1;

                while (left >= start && right < n &&
                       s[left] == s[right]) {

                    int len = right - left + 1;

                    if (len >= k) {
                        count++;
                        start = right + 1;
                        found = true;
                        break;
                    }

                    left--;
                    right++;
                }

                if (found)
                    break;
            }

            if (!found)
                break;
        }

        return count;
    }
};