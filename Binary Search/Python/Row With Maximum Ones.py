## brute TC:O(rows * cols) SC:O(1)
class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        maxCnt = 0
        ind = 0
        for i in range(len(mat)):
            cnt = 0
            for j in range(len(mat[0])):
                if mat[i][j] == 1:
                    cnt= cnt+1
                    if cnt>maxCnt:
                        maxCnt =cnt
                        ind = i
        return [ind,maxCnt]
        
# optimal (if each row is sorted in matrix) TC:O(rows * log n) SC:O(1)

class Solution:
    def bs(self,arr):
        low = 0 
        high=len(arr)-1
        while low<=high:
            mid  = low+(high-low)//2;
            if arr[mid]:high = mid-1
            else: low = mid+1
        return low
        
    def rowWithMax1s(self, arr):
        max_cnt = 0
        idx = 0
        for i in range(len(arr)):
            cnt = len(arr[0]) - self.bs(arr[i])
            if cnt>max_cnt:
                max_cnt=cnt
                idx= i 
        return idx
