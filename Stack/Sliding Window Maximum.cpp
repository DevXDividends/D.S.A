// brute TC:O(n^2) SC:O(n^2) 
class Solution {
public:
    int maxEle(vector<int>& arr) {
        int maxNum = INT_MIN;
        for (int n : arr)
            maxNum = max(maxNum, n);
        return maxNum;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> karr; 
        vector<int> ans;
        for (int i = 0; i < n-k+1; i++) {
            vector<int> temp;
            for (int j = 0; j < k; j++) {
                temp.emplace_back(nums[i+j]);
            }
            karr.emplace_back(temp);
        }
        for (int i = 0; i < karr.size(); i++) {
            ans.emplace_back(maxEle(karr[i]));
        }
        return ans;
    }
};
// better TC:O(n^2) SC:O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n - k + 1; i++) {
            int maxEle = INT_MIN;
            for (int j = 0; j < k; j++) {
                maxEle = max(maxEle, nums[i + j]);
            }
            ans.emplace_back(maxEle);
        }
        return ans;
    }
};
// optimised TC:O(2n) SC:O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.front() <= i - k)
                q.pop_front();
            while (!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
            if (i >= k - 1)
                ans.emplace_back(nums[q.front()]);
        }
        return ans;
    }
};
