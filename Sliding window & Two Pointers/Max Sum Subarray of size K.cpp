// TC"O(n) SC:O(1)
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int l = 0;
        int r = k-1;
        int maxSum = 0;
       int windowSum = 0;
       for(int i=0;i<k;i++)
            windowSum+=arr[i];
        
        maxSum = windowSum;
        while(r<n){
            windowSum-=arr[l++];
            r++;
            windowSum+=arr[r];
            maxSum= max(maxSum,windowSum);
        }
        return maxSum;
        
    }
};
