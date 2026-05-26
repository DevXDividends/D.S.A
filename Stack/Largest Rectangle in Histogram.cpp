// brute TC:O(n^2) SC:O(n) 
class Solution { 
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            int lcnt = 0;
            for (int j = i-1; j >= 0; j--) {
                if (heights[j] >= heights[i])
                    lcnt++;
                else
                    break;
            }
            int rcnt = 0;
            for (int k = i+1; k < n; k++) {
                if (heights[k] >= heights[i])
                    rcnt++;
                else
                    break;
            }
            maxArea = max(maxArea, heights[i] * (lcnt + rcnt + 1));
        }
        return maxArea;
    }
};

/// better TC:O(3n) SC:O(2n)
class Solution {
public:
    void pse(vector<int>& arr, vector<int>& pse) {
        stack<int> stk;
        for (int i = 0; i < arr.size(); i++) {
            while (!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            pse[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
    }
    void nse(vector<int>& arr, vector<int>& pse) {
        stack<int> stk;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            pse[i] = stk.empty() ? arr.size() : stk.top();
            stk.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return -1;
        int n = heights.size();
        int maxArea = 0;
        vector<int> psea(n);
        vector<int> nsea(n);
        pse(heights, psea);
        nse(heights, nsea);

        for (int i = 0; i < n; i++) {
            int left = psea[i];
            int right = nsea[i];
            maxArea = max(maxArea, heights[i] * (right - left - 1));
        }
        return maxArea;
    }
};
// optimal TC:O(n) SC:O(n) 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int maxArea = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int element = stk.top();
                stk.pop();
                int nse = i;
                int pse = stk.empty() ? -1 : stk.top();
                maxArea = max(maxArea, heights[element] * (nse - pse - 1));
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int element = stk.top();
                stk.pop();
                int nse = n;
                int pse = stk.empty() ? -1 : stk.top();
                maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }
        return maxArea;
    }
};
