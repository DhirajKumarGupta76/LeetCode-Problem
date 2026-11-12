
class Solution {
public:

    // Check whether we can make m bouquets
    // within the given number of days
    bool isPossible(vector<int>& bloomDay, int day, int m, int k) {

        int cnt = 0;       // Count consecutive bloomed flowers
        int bouquets = 0; // Count total bouquets

        for(int i = 0; i < bloomDay.size(); i++) {

            if(bloomDay[i] <= day) {

                // Flower has bloomed
                cnt++;

            }
            else {

                // Consecutive sequence breaks
                bouquets += cnt / k;
                cnt = 0;

            }
        }

        // Handle remaining consecutive flowers
        bouquets += cnt / k;

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        // Impossible to make m bouquets
        if((long long)m * k > n) {
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(isPossible(bloomDay, mid, m, k)) {

                // Possible answer, search for minimum days
                ans = mid;
                high = mid - 1;

            }
            else {

                // Need more days for flowers to bloom
                low = mid + 1;

            }
        }

        return ans;
    }
};
