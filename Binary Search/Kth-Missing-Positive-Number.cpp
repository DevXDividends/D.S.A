// Brute force approach TC: O(n)  SC:O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 0;
        for (int n : arr) {
            if (n <= k)
                k++;
            else
                return k;
        }
        return k;
    }
};


