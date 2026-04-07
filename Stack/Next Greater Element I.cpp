// TC:O(n * m) SC:O(n)
class Solution {
public:
    int find(vector<int>& arr, int ele, int pos) {
        for (int i = pos + 1; i < arr.size(); i++)
            if (arr[i] > ele)
                return arr[i];
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge;
        for (int i = 0; i < nums1.size(); i++) {
            int j = 0;
            for (; nums2[j] != nums1[i]; j++)
                ;
            int ele = find(nums2, nums1[i], j);
            nge.emplace_back(ele);
        }
        return nge;
    }
};

// approach 2 TC:O(n) SC:O(n)
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        stack<int> stk;
        vector<int> ans(n);
        
        for(int i=n-1;i>=0;i--){
            
            while(!stk.empty() && arr[i]>=stk.top())
                stk.pop();
            
            if(stk.empty())
                 ans[i] = -1;
            else
                ans[i] = stk.top();
            
            stk.push(arr[i]);
        }
        return ans;
    }
};
