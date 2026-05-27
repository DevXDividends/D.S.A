// TC:Orows * cols) SC:O(rows * cols)
class Solution {
public:
    int largestRecInHist(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                int nse = i;
                int element = arr[stk.top()];stk.pop();
                int pse = stk.empty() ? -1 : stk.top();
                maxArea = max(maxArea, element * (nse - pse - 1));
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int nse = n;
            int element = arr[stk.top()];stk.pop();
            int pse = stk.empty() ? -1 :stk.top();
            maxArea = max(maxArea, element * (nse - pse - 1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxArea = 0;
        vector<vector<int>> prefix(rows, vector<int>(cols, 0));
        // create prefix array
        for (int i = 0; i < cols; i++) {
            int sum = 0;
            for (int j = 0; j < rows; j++) {
                if (matrix[j][i] == '0')
                    sum = 0;
                else
                    sum += matrix[j][i] - '0';
                prefix[j][i] = sum;
            }
        }
        for (int i = 0; i < rows; i++) {
            maxArea = max(maxArea, largestRecInHist(prefix[i]));
        }
        return maxArea;
    }
};
