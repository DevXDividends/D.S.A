// TC:O(log n) SC:O(1)
class Solution:
    def hIndex(self, citations: List[int]) -> int:
     n=len(citations)
     low=0
     high=n-1
     while low<=high:
        mid=low+(high-low)//2
        h=n-mid
        if citations[mid]==h:return h
        if citations[mid]<h:low=mid+1
        else:high=mid-1
     return n-low
        
