// TC:O(n^2) SC:O(1)
class Solution:
    def countKDifference(self, nums, k):
        cnt = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if abs(nums[i] - nums[j]) == k:
                    cnt += 1
        return cnt

// TC:O(n) SC:O(n)
class Solution:
    def countKDifference(self, nums, k):
        mpp = {}
        cnt = 0
        for n in nums:
            cnt += mpp.get(n - k, 0)
            cnt += mpp.get(n + k, 0)
            mpp[n] = mpp.get(n, 0) + 1
        return cnt
