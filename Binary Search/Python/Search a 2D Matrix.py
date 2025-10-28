// brute TC:O(rows * cols) SC:O(1)
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == target:return True
        return False

## optimal TC:O(log(rows*cols)) SC:(1)
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        low = 0
        high = rows * cols-1
        while low<=high:
            mid = low+(high-low)//2
            row=mid//cols
            col = mid%cols
            if matrix[row][col] == target:return True
            if matrix[row][col]<target: low=mid+1
            else:high=mid-1
        return False
