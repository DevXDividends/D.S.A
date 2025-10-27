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
