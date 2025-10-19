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
