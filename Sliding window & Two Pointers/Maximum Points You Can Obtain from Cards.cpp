// TC:O(2k) SC:O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxScore = INT_MIN;
        int lSum = 0;
        int rSum = 0;
        for (int i = 0; i < k; i++)
            lSum += cardPoints[i];

        maxScore = lSum;
        int rIndex = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            lSum -= cardPoints[i];
            rSum += cardPoints[rIndex--];
            maxScore = max(maxScore, lSum + rSum);
        }
        return maxScore;
    }
};
