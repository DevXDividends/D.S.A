// TC:O(n) SC:O(n)
class Solution {
public:
    int solve(int n, int steps, unordered_map<int, int>& memo) {
        if (steps == n)
            return 1;
        if (steps > n)
            return 0;
        if (memo.find(steps) != memo.end())
            return memo[steps];
        int left = solve(n, steps + 1, memo);
        int right = solve(n, steps + 2, memo);
        memo[steps] = left + right;

        return left + right;
    }
    int climbStairs(int n) {
        unordered_map<int, int> memo;
        return solve(n, 0, memo);
    }
};
