// brute force
TC:O(n^3) SC:O(n^3)
class Solution {
public:
    void getallsubarrs(vector<vector<int>>& subarr, vector<int>& arr) {
        for (int st = 0; st < arr.size(); st++) {
            for (int end = st; end < arr.size(); end++) {
                vector<int> sub;
                for (int i = st; i <= end; i++) {
                    sub.emplace_back(arr[i]);
                }
                subarr.emplace_back(sub);
            }
        }
    }
    int getmins(vector<int>& arr) {
        int min = INT_MAX;
        for (int n : arr) {
            if (n < min)
                min = n;
        }
        return min;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<vector<int>> subarr;
        getallsubarrs(subarr, arr);
        vector<int> mins;
        for (int i = 0; i < subarr.size(); i++) {
            mins.emplace_back(getmins(subarr[i]));
        }
        long long sum = 0;
        for (int n : mins) {
            sum += n;
        }
        const int MOD = 1e9 + 7;

        return sum % MOD;
    }
};
// better TC:O(n^2) SC:O(1)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        int n = arr.size();
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
           int mini = INT_MAX;
            for (int j = i; j < n; j++) {
                mini = min(mini, arr[j]);
                sum += mini;
            }
        }
        return sum % MOD;
    }
};
