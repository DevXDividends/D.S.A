// TC:O(n) SC:O(1)
class Solution {
public:
    int f(int pos) { return pos % 2 == 0 ? 5 : 4; }
    int countGoodNumbers(long long n) {
        long long cnt = 1;
        constexpr int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            cnt = (cnt * f(i)) % MOD;
        }
        return cnt;
    }
};
// TC:O(2 log n) SC:O(1) 
class Solution {
public:
    long long Pow(long long num, int exp) {
        long long res = 1;
        constexpr int MOD = 1e9 + 7;

        long long power = exp;

        while (power > 0) {
            if (power % 2 == 1)
                res = (res * num) % MOD;
            num = (num * num) % MOD;
            power /= 2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long cnt = 1;
        constexpr int MOD = 1e9 + 7;
        long long  cntEvenInd = ceil((double)n / 2);
        long long cntOddInd = n - cntEvenInd;
        long long even = Pow(5, cntEvenInd);
        long long odd = Pow(4, cntOddInd);
        return (even * odd) % MOD;
    }
};
