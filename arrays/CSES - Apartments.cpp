// TC:O(n log n + m log m) SC:O(1)
class Solution {
public:
    int findMaxApartments(vector<int>& applicants, vector<int>& apartments, int k) {
        sort(applicants.begin(), applicants.end());
        sort(apartments.begin(), apartments.end());
        int i = 0, j = 0, ans = 0;
        while (i < (int)applicants.size() && j < (int)apartments.size()) {
            if (abs(applicants[i] - apartments[j]) <= k) {
                ans++;
                i++;
                j++;
            } else if (applicants[i] - apartments[j] > k) {
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};
