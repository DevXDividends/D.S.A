// TC:O(log n) SC:O(log n)
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        if (n % 4 != 0)
            return false;
        return isPowerOfFour(n / 4);
    }
};
// TC:O(1) SC:O(1)
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && 1073741824 % n == 0;
    }
}; 
