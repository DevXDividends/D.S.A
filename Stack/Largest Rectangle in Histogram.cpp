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
