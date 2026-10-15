// brute force  TC:O(n^2) SC:O(n)
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
           int n = arr.size();
           vector<int> ans(n,-1);
           for(int i=0;i<n;i++){
             for(int j=i-1;j>=0;j--){
                if(arr[j]<arr[i]){
                   ans[i]=arr[j];
                   break;
                 }
              }
           }  
        return ans;
    }
};
// optimal approach TC:O(2n) SC:O(n) 
// Monotonic stack — TC:O(n) SC:O(n)
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top() >= arr[i]) stk.pop();
            ans[i] = stk.empty() ? -1 : stk.top();
            stk.push(arr[i]);
        }
        return ans;
    }
};
