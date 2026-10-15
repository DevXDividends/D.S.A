// TC:O(log n) SC:O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long original = x;
        long long reversed = 0;
        long long temp = x;
        while (temp > 0) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }
        return reversed == original;
    }
};
