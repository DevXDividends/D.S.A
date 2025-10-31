// TC:O(n^3) SC:O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSize = INT_MAX;
        for (int i = 0; i < nums.size(); i++) { //n 
            for (int j = i; j < nums.size(); j++) { // n*n-1
                int sum = 0;
                for (int end = i; end <= j; end++) {
                    sum += nums[end];
                    if (sum >= target)
                        minSize = min(minSize, (j - i) + 1);
                }
            }
        }
        return (minSize != INT_MAX) ? minSize : 0;
    }
};
// TC:O(n^2) SC:O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSize = INT_MAX;
        for (int i = 0; i < nums.size(); i++) { // n
            int sum = 0;
            for (int j = i; j < nums.size(); j++) { // n*n-1
                sum += nums[j];
                if (sum >= target)
                    minSize = min(minSize, (j - i) + 1);
            }
        }
        return (minSize != INT_MAX) ? minSize : 0;
    }
};

// optimal TC:O(n) SC:O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minSize = INT_MAX;
        int sum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target) {
                minSize = min(minSize, right - left + 1);
                sum -= nums[left++];
            }
        }
        return (minSize == INT_MAX) ? 0 : minSize;
    }
};
