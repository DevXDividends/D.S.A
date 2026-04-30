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
