brute TC:O(n^2) SC:O(n) 
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int  n = arr.size();
        vector<int> nse(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[i]){
                    nse[i]  = arr[j];
                    break;
                }
            }
        }
        return nse;
    }
};
optimal TC:O(n) SC:O(2n)
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int> stk;
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && stk.top()>arr[i])
             stk.pop();
            nse[i] = stk.empty()?-1:stk.top();
            stk.push(arr[i]);
        }
        return nse;
    }
};
