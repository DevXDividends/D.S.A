 // Brute force TC: O(n * maxLimit - minLimit )SC:O(1)
class Solution {
public:
    bool check(vector<int>& a, int val, int k) {
        int cnt = 1;
        int allocated = 0;
        for (int n : a) {
            if (allocated + n > val) {
                allocated = n;
                cnt++;
            } else
                allocated += n;
        }
        return (cnt <= k);
    }
    int splitArray(vector<int>& a, int k) {
        if (k > a.size())
            return -1;
        int midLim = *max_element(a.begin(), a.end());
        int maxlim = accumulate(a.begin(), a.end(), 0);
        for (int i = midLim; i <= maxlim; i++) {
            if (check(a, i, k))
                return i;
        }
        return -1;
    }
};

// optimal approach : TC:O(n⋅log(sum(a)−max(a))) SC:O(1)  
class Solution {
public:
    bool check(vector<int>& a, int val, int k) {
        int cnt = 1;
        int allocated = 0;
        for (int n : a) {
            if (allocated + n > val) {
                allocated = n;
                cnt++;
            } else
                allocated += n;
        }
        return (cnt <= k);
    }
    int splitArray(vector<int>& a, int k) {
        if (k > a.size())
            return -1;
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(a, mid, k))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
