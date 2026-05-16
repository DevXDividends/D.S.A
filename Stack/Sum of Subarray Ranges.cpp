// brute TC:O(n^3 * n log n) SC:O(n^3)
class Solution {
public:
    void getallsubarr(vector<int>& nums, vector<vector<int>>& subarr) {
        for (int st = 0; st < nums.size(); st++) {
            for (int end = st; end < nums.size(); end++) {
                vector<int> sub;
                for (int j = st; j <= end; j++) {
                    sub.emplace_back(nums[j]);
                }
                sort(sub.begin(), sub.end());
                subarr.emplace_back(sub);
            }
        }
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<vector<int>> subarr;
        getallsubarr(nums, subarr);
        long long sum = 0;
        for (int i = 0; i < subarr.size(); i++) {
            sum += (subarr[i][subarr[i].size() - 1] - subarr[i][0]);
        }
        return sum;
    }
};
// better TC:O(n^2) SC:O(1)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int largest = nums[i];
            int smallest = nums[i];
            for (int j = i + 1; j < n; j++) {
                largest = max(nums[j], largest);
                smallest = min(nums[j], smallest);
                sum += largest - smallest;
            }
        }
        return sum;
    }
};
// optimal TC:O(n) SC:O(n) 
class Solution {
public:
    long long sumOfMinimums(vector<int>& nums) {

        int n = nums.size();

        vector<long long> left(n), right(n);
        stack<int> stk;

        // Previous Smaller
        for (int i = 0; i < n; i++) {

            while (!stk.empty() && nums[stk.top()] > nums[i])
                stk.pop();

            left[i] = stk.empty() ? (i + 1) : (i - stk.top());

            stk.push(i);
        }

        while (!stk.empty())
            stk.pop();

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {

            while (!stk.empty() && nums[stk.top()] >= nums[i])
                stk.pop();

            right[i] = stk.empty() ? (n - i) : (stk.top() - i);

            stk.push(i);
        }

        long long total = 0;

        for (int i = 0; i < n; i++) {
            total += (long long)nums[i] * left[i] * right[i];
        }

        return total;
    }

    long long sumOfMaximums(vector<int>& nums) {

        int n = nums.size();

        vector<long long> left(n), right(n);
        stack<int> stk;

        // Previous Greater
        for (int i = 0; i < n; i++) {

            while (!stk.empty() && nums[stk.top()] < nums[i])
                stk.pop();

            left[i] = stk.empty() ? (i + 1) : (i - stk.top());

            stk.push(i);
        }

        while (!stk.empty())
            stk.pop();

        // Next Greater
        for (int i = n - 1; i >= 0; i--) {

            while (!stk.empty() && nums[stk.top()] <= nums[i])
                stk.pop();

            right[i] = stk.empty() ? (n - i) : (stk.top() - i);

            stk.push(i);
        }

        long long total = 0;

        for (int i = 0; i < n; i++) {
            total += (long long)nums[i] * left[i] * right[i];
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {

        long long maxSum = sumOfMaximums(nums);

        long long minSum = sumOfMinimums(nums);

        return maxSum - minSum;
    }
};
