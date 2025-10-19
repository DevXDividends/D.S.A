//Brute force TC:O(n  * sum(arr)  - max(arr)) SC:O(1)
class Solution:
    def findPages(self, arr, k):
        # code here
        if k>len(arr): return -1
        minLim  = max(arr)
        maxLim = sum(arr)
        for i in range(1,maxLim):
            if self.check(arr,i,k):return i
        
        return -1;
    
    def check(self,a,val,students):
        cnt=1
        pagesAllo=0
        for i in range(len(a)):
            if pagesAllo + a[i] > val:
                pagesAllo=a[i]
                cnt=cnt+1;
            else:
                pagesAllo+=a[i]
        return cnt<=students


## optimal approach TC: O(n⋅ * log(maxLimit−minLimit)) SC:O(1) 
class Solution:
    def findPages(self, arr, k):
        
        if(k>len(arr)): return -1;
        low = max(arr)
        high = sum(arr)
        while low<=high:
            mid  = low+(high-low)//2;
            if self.check(arr,mid,k): high=mid-1
            else: low=mid+1
        return low
        
    def check(self,a,val,students):
        cnt=1
        pagesAllo = 0
        for i in range(len(a)):
            if pagesAllo+a[i] > val:
                pagesAllo = a[i]
                cnt=cnt+1
            else:
                pagesAllo+=a[i]
        return cnt<=students
