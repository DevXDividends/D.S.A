 // brute TC:O(k*n) + O(n)
class Solution {
public:
    double minMaxDist(vector<int> &stations, int K) {
        int n = stations.size();
        vector<int> placed(n - 1, 0);

        for (int gasStations = 0; gasStations < K; gasStations++) {
            double maxSection = -1;
            int maxInd = -1;

            for (int i = 0; i < n - 1; i++) {
                double diff = stations[i + 1] - stations[i];
                double secDiff = diff / (placed[i] + 1);
                if (secDiff > maxSection) {
                    maxSection = secDiff;
                    maxInd = i;
                }
            }

            placed[maxInd]++;
        }

        double maxAns = -1;
        for (int i = 0; i < n - 1; i++) {
            double diff = stations[i + 1] - stations[i];
            double secDiff = diff / (placed[i] + 1);
            maxAns = max(maxAns, secDiff);
        }

        return maxAns;
    }
};
// better

// optimal 




opsjdfajbkjadajsdhkajsdhajd
