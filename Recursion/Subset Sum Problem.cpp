// TC:O(2^n) SC:O(n)
class Solution {
  public:
   bool findSubsetSum(int ind,vector<int> &a,int sum){
       if(sum<0)return false;
       if(ind == a.size()){
           if(sum == 0)return true;
           return false;
       }
       // take
       if(findSubsetSum(ind+1,a,sum-a[ind]) == true)return true;
       // not take
       if(findSubsetSum(ind+1,a,sum) == true)return true;
       
       
   }
    bool isSubsetSum(vector<int>& arr, int sum) {
        if(sum<0)return true;
        return findSubsetSum(0,arr,sum);
    }
};
