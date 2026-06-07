// Brute force TC:O(n² + n log n + n) SC:O(3n)
class Solution {
public:
    int linearSearch(vector<pair<int, int>>& arr, int num) {
        int ans = -1;
        for (int i = arr.size() - 1; i >= 0; i--)
            if (arr[i].first >= num)
                ans = arr[i].second;
        return ans;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> start, end;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
            start.push_back({intervals[i][0], i});//O(n)
        for (int i = 0; i < n; i++)
            end.push_back({intervals[i][1], i}); // O(n)
        sort(start.begin(), start.end()); // O(n log n)
        sort(end.begin(), end.end());  // O(n log n)

        for (int i = 0; i < n; i++) { // overall O(n^2)
            ans[end[i].second] = linearSearch(start, end[i].first);
        }
        return ans;
    }
};
 // optmial TC:O(n log n) SC:O(3n)
class Solution {
public:
    int LowerB(vector<pair<int, int>>& arr, int num) {
        int ans = -1;
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid].first >= num) {
                ans = arr[mid].second;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> start;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
            start.push_back({intervals[i][0], i}); // O(n)

        sort(start.begin(), start.end()); // O(n log n)

        for (int i = 0; i < n; i++) { // overall O(log n)
            ans[i] = LowerB(start, intervals[i][1]);
        }
        return ans;
    }
};
