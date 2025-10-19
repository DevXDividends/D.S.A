## brute force
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
