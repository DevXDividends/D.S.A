brute TC:O(a) + O(b) + O(n log n) SC:O(a+b)
  class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        vector<int> ans(a.begin(),a.end());
        for(int n:b) ans.emplace_back(n);
        sort(ans.begin(),ans.end());
        if(ans.size()>=k) return ans[k-1];
        return -1;
        
    }
};

//better  TC:o(b) + o(n log n) SC:O(1)
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        for(int n:b) a.emplace_back(n);
        sort(a.begin(),a.end());
        if(a.size()>=k) return a[k-1];
        return -1;
        
    }
};

// optimal  TC:O(log (min(a,b)) SC:O(1)
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n1 = a.size(), n2 = b.size();
        if (n1 > n2) return kthElement(b, a, k); // ensure a is smaller
        
        int low = max(0, k - n2);
        int high = min(k, n1);
        
        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = k - mid1; // how many from b
            
            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;
            
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return -1; // shouldn't reach here
    }
};
