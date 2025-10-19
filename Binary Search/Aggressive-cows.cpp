 //Brute force TC: O(n×maxDist) SC:O(1) 
class Solution {
  public:
  bool check(vector<int> &a,int dist,int cows){
      int cnt=1;
      int prev=a[0];
      for(int i=1;i<a.size();i++){
          if(a[i]-prev>=dist){
              prev=a[i];
              cnt++;
          }
      }
      return (cnt>=dist);
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int maxdist=stalls.back()-stalls[0];
        int res=0;
        for(int i=1;i<=maxdist;i++){
            if(check(stalls,i,k)){
                res=i;
            }
        }
        return res;
    }
};

// optimal solution TC:O(log maxDist) * O(n) SC:O(1)
class Solution {
  public:
  bool check(vector<int> &a,int dist,int cows){
      int cnt=1;
      int prev=a[0];
      for(int i=1;i<a.size();i++){
          if(a[i]-prev>=dist){
              cnt++;
              prev=a[i];
          }
      }
      return (cnt>=cows);
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int res=-1;
        
        int low=0,high=stalls.back()-stalls[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(stalls,mid,k)){
                res=mid;
                low=mid+1;
            }else high=mid-1;
        }
        return res;
    }
};
