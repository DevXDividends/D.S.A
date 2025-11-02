// TC:O(log n) SC:O(1)
class Solution:
    def findOcc(self, a, val, flag):
        low, high = 0, len(a) - 1
        ans = -1
        while low <= high:
            mid = low + (high - low) // 2
            if a[mid] == val:
                ans = mid
                if flag:   # find first occurrence
                    high = mid - 1
                else:      # find last occurrence
                    low = mid + 1
            elif a[mid] < val:
                low = mid + 1
            else:
                high = mid - 1
        return ans

    def find(self, arr, x):
        first = self.findOcc(arr, x, True)
        last = self.findOcc(arr, x, False)
        return [first, last]
