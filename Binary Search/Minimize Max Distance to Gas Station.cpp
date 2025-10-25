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
// better  $$TC = O(N) + O(K * log(N-1))  SC = O(N) + O(N) = O(N)
class Solution {
 public:
    double minMaxDist(vector<int> &stations, int K) {
        int n = stations.size();
        if (n <= 1) {
            return 0.0; // If there are 0 or 1 stations, the max distance is 0.
        }
        vector<int> placed(n - 1, 0);
        priority_queue<pair<long double, int>> pq; 
        for (int i = 0; i < n - 1; i++) {
            pq.push({(long double)(stations[i+1] - stations[i]), i});
        }
        for (int gasStations = 0; gasStations < K; gasStations++) {
            auto [length, idx] = pq.top(); pq.pop();
            placed[idx]++; // Increment the count of stations added to this segment
            long double newDist = (long double)(stations[idx+1] - stations[idx]) / (placed[idx] + 1);
            pq.push({newDist, idx}); // Push the updated (smaller) segment distance back
        }
        return pq.top().first;
    }
};
// optimal 




opsjdfajbkjadajsdhkajsdhajd
