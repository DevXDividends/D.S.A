class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mpp = {}
        n = len(nums)
        for i in range(n):
            comp = target - nums[i]
            if comp in mpp:
                return [i, mpp[comp]]

            mpp[nums[i]] = i

        return []
