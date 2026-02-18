class Solution {
public:
    long long calcHours(vector<int>& piles, int speed) {
        long long h_count = 0;
        for (int x : piles) {
            h_count += (x + speed - 1) / speed;
        }
        return h_count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long hrs = calcHours(piles, mid);

            if (hrs > h) {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }
};