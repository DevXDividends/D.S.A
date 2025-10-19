## brute force  O(n×maxDist) SC:O(1) 
class Solution:
    def aggressiveCows(self, stalls, k):
        # code here
        stalls.sort();
        maxDist=stalls[-1]-stalls[0];
        res=-1;
        for i in range(1,maxDist):
            if self.check(stalls,i,k):
                res=i
                
        return res
        
    def check(self,a,dist,cows):
        cnt=1
        prev=a[0]
        for i in range(len(a)):
            if a[i]-prev >= dist:
                prev=a[i]
                cnt = cnt+1;
        return cnt>=dist


## optimal  solution TC:O(log maxDist) * O(n) SC:O(1)
class Solution:
    def aggressiveCows(self, stalls, k):
        stalls.sort()
        res=-1;
        low=0 
        high=stalls[-1]  - stalls[0]
        while low<=high:
            mid=low+(high-low)//2;
            if self.check(stalls,mid,k):
                res=mid
                low=mid+1
            else:
                    high=mid-1
        return res
        
    def check(self,a,dist,cows):
        prev=a[0]
        cnt=1
        for i in range(1,len(a)):
            if a[i]- prev >= dist:
                cnt=cnt+1
                prev=a[i]
        return cnt>=cows
        

