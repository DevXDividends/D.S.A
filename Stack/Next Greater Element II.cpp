// brute TC:O(n^2) SC:O(n) 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < i + n; j++) {
                int ind = j % n;
                if (arr[ind] > arr[i]) {
                    nge[i] = arr[ind];
                    break;
                }
            }
        }
        return nge;
    }
};
// optimal TC:O(4n) SC:O(2n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> stk;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= arr[i % n])
                stk.pop();

            if (i < n)
                nge[i] = stk.empty() ? -1 : stk.top();
            stk.push(arr[i % n]);
        }
        return nge;
    }
};
