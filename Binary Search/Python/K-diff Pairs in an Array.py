// TC:O(n^2) SC:O(1)
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        nums.sort()
        maxCnt = 0
        n = len(nums)

        for i in range(n):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            for j in range(i + 1, n):
                if abs(nums[i] - nums[j]) == k:
                    maxCnt += 1
                    break
                elif abs(nums[i] - nums[j]) > k:
                    break
        return maxCnt

//TC:O(n log n) SC:O(1)
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        nums.sort()
        maxCnt=0
        n = len(nums)
        for i in range(n):
            if i!=0 and nums[i]==nums[i-1]:continue
            comp=nums[i]+k
            low=i+1
            high=n-1
            while low<=high:
                mid=low+(high-low)//2
                if(nums[mid]==comp):
                    maxCnt=maxCnt+1
                    break
                elif nums[mid]>comp:
                    high=mid-1
                else: low=mid+1
        return maxCnt

        

        
