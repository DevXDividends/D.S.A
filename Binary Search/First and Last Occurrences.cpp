// TC:O(log n) SC:O(1)
class Solution {
  public:
  
  int findOcc(vector<int> &a,int val,bool flag){
      int low=0,high=a.size()-1;
      while(low<=high){
          int mid = low+(high-low)/2;
          if(a[mid]==val){
              if(flag) high=mid-1; // go left
              else low=mid+1;//go right
          }else if(a[mid]<val) low=mid+1;
          else high=mid-1;
      }
      return (flag)?((a[low]==val)?low:-1):((a[high]==val)?high:-1);
  }
  
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int first = findOcc(arr,x,true);
        int last = findOcc(arr,x,false);
        return {first,last};
    }
};
