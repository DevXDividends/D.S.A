TC:O(n) SC:O(2n)
class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        //  code here
        if (arr.empty())
        return {};
        int n = arr.size();
        stack<int> stk;
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!stk.empty() && arr[i] >= stk.top())
             stk.pop();
            pse[i] = stk.empty()?-1:stk.top();
            stk.push(arr[i]);
        }
        return pse;
        
    }
};
