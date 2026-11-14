// TC:O(n) SC:O(n)

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes,
                      vector<int>& runningCosts,
                      long long budget) {

        int n = chargeTimes.size();

        int left = 0, right = 0;
        long long sumBudget = 0;
        int ans = 0;

        deque<int> dq;

        while (right < n) {

            // 1. Maintain running sum
            sumBudget += runningCosts[right];

            // 2. Maintain decreasing deque
            while (!dq.empty() &&
                   chargeTimes[dq.back()] <= chargeTimes[right]) {
                dq.pop_back();
            }

            dq.push_back(right);

            // 3. Calculate window size and cost
            int k = right - left + 1;

            long long cost = chargeTimes[dq.front()]
                             + 1LL * k * sumBudget;

            // 4. Shrink window until valid
            while (cost > budget) {

                // Remove expired maximum index
                if (dq.front() == left) {
                    dq.pop_front();
                }

                sumBudget -= runningCosts[left];
                left++;

                k = right - left + 1;

                if (left <= right) {
                    cost = chargeTimes[dq.front()]
                           + 1LL * k * sumBudget;
                } else {
                    break;
                }
            }

            // 5. Update answer
            ans = max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
};
