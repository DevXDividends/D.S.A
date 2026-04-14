// Brute TC:O(3n) SC:O(2n)
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int total = 0;

        vector<int> prefixMax(n);
        vector<int> suffixMax(n);

        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++)
            prefixMax[i] = max(prefixMax[i - 1], height[i]);

        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffixMax[i] = max(suffixMax[i + 1], height[i]);

        for (int i = 0; i < n; i++) {
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];

            if (height[i] < leftMax && height[i] < rightMax)
                total += min(leftMax, rightMax) - height[i];

        }
        return total;
    }
};
// optimal TC:O(n) SC:O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l, r, leftMax, rightMax;
        l = leftMax = rightMax = 0;
        r = height.size() - 1;
        while (l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            if (leftMax < rightMax) {
                ans += leftMax - height[l];
                l++;
            } else {
                ans += rightMax - height[r];
                r--;
            }
        }
        return ans;
    }
};
