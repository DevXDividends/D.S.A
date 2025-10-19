 // Brute force TC: O(n * maxLimit - minLimit )SC:O(1)
class Solution:
    def splitArray(self, a: List[int], k: int) -> int:
        if(k>len(a)): return -1
        minLim = max(a)
        maxLim = sum(a)
        for i in range(minLim,maxLim):
            if self.check(a,i,k): return i
        return -1
    
    def check(self,a,val,k):
        cnt=1
        allo = 0
        for i in range(len(a)):
            if allo + a[i] > val:
                allo = a[i]
                cnt=cnt+1
            else:
                allo += a[i]
        return cnt<=k

// optimal approach : TC:O(n⋅log(sum(a)−max(a))) SC:O(1)  
class Solution:
    def splitArray(self, a: List[int], k: int) -> int:
        if k > len(a):
            return -1
        low = max(a)
        high = sum(a)
        while low<=high:
            mid = low+(high-low) // 2
            if self.check(a,mid,k): high=mid-1
            else : low=mid+1
        return low
    
    def check(self,a,val,k):
        cnt=1
        allo = 0
        for i in range(len(a)):
            if allo + a[i] > val:
                allo = a[i]
                cnt=cnt+1
            else:
                allo += a[i]
        return cnt<=k
