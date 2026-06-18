// TC:O(2n) SC:O(1)
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        int l = 0,r = 0;
        int currSum = 0;
        while(r<n){
            currSum+=arr[r];
            while(currSum>target)
                currSum-=arr[l++];
                
            if(currSum == target)
                return {l+1,r+1};
                
            r++;
        }
        return {-1};
    }
};
