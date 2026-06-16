// TC:O(n^2) SC:O(1)
class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int basket1 = -1, basket2 = -1;
            for (int j = i; j < n; j++) {
                if (basket1 == -1)
                    basket1 = nums[j];
                if (basket2 == -1 && nums[j] != basket1)
                    basket2 = nums[j];
                if (nums[j] == basket1 || nums[j] == basket2)
                    maxLen = max(maxLen, j - i + 1);
                else
                    break;
            }
        }
        return maxLen;
    }
};
// TC:O(2n) SC:O(3)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0;
        int maxLen = 0;
        unordered_map<int, int> mpp;
        while (r < n) {
            mpp[fruits[r]]++;
            if (mpp.size() > 2) {
                while (mpp.size() > 2) {
                    mpp[fruits[l]]--;
                    if (mpp[fruits[l]] == 0)
                        mpp.erase(fruits[l]);
                    l++;
                }
            }
            if (mpp.size() <= 2)
                maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
// TC:O(n) SC:O(3)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0;
        int maxLen = 0;
        unordered_map<int, int> mpp;
        while (r < n) {
            mpp[fruits[r]]++;
            if (mpp.size() > 2) {
                if (mpp.size() > 2) {
                    mpp[fruits[l]]--;
                    if (mpp[fruits[l]] == 0)
                        mpp.erase(fruits[l]);
                    l++;
                }
            }
            if (mpp.size() <= 2)
                maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
