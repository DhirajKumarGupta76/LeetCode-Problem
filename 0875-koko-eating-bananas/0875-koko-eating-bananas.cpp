
class Solution {
public:

    // Check whether Koko can finish within h hours
    bool canEat(vector<int>& piles, int h, int k) {

        long long hours = 0;

        for (int i = 0; i < piles.size(); i++) {

            // Calculate hours required for current pile
            hours += (piles[i] + k - 1) / k;

        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;

        // Maximum pile size is the maximum possible speed
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canEat(piles, h, mid)) {

                // Possible answer, try smaller speed
                ans = mid;
                high = mid - 1;

            }
            else {

                // Speed is too slow, increase it
                low = mid + 1;

            }
        }

        return ans;
    }
};
