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
// optimal TCL:O(n) + O(n) + O(n) = O(n)
// SC:O(n) + O(n) + O(n) = O(n)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++)
            total = (total + (long long )arr[i] * left[i] * right[i]) % mod;
        return total;
    }
};
