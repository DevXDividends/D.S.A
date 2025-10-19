//Brute force TC:O(n  * sum(arr)  - max(arr)) SC:O(1)
class Solution {
  public:
  bool check(vector<int> &a,int val,int students){
      int cnt=1;
      int pagesAllo = 0;
      for(int n:a){
          if(pagesAllo + n > val){
              pagesAllo=n;
              cnt++;
          }else{
              pagesAllo+=n;
          }
      }
      return (cnt<=students);
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n) return -1;
        int minlimit = *max_element(arr.begin(),arr.end());
        int maxLimit = accumulate(arr.begin(),arr.end(),0);
        for(int i=minlimit;i<=maxLimit;i++){
            if(check(arr,i,k)) return i;
        }
    }
};

// optimal approach TC: O(n⋅ * log(maxLimit−minLimit)) SC:O(1) 
class Solution {
  public:
  bool check(vector<int> &a,int val,int students){
      int cnt=1;
      int pagesAllo=0;
      for(int n:a){
          if(pagesAllo+n>val){
              pagesAllo=n;
              cnt++;
          }else{
              pagesAllo+=n;
              
          }
      }
      return (cnt<=students);
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size()) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        int mid;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(arr,mid,k)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
