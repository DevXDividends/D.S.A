##  Brute approach : TC:O(n) SC:O(1)

class Solution:
    def findMin(self, nums: List[int]) -> int:
        min = sys.maxsize
        for i in range(len(nums)):
            if nums[i] < min:min=nums[i]
        return min

  ##  optimal approach TC:O(log n) SC:O(1)
  class Solution:
    def findMin(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if mid > 0 and nums[mid] < nums[mid - 1]:
                return nums[mid]
            if nums[mid] > nums[high]:
                low = mid + 1
            elif nums[mid] < nums[high]:
                high = mid
            else:
                high = high - 1
        return nums[low]
