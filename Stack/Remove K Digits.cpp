// TC:O(3n + k) SC:O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k >= n)
            return "0";
        stack<char> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && k > 0 && stk.top() - '0' > num[i] - '0') {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while (k != 0) {
            stk.pop();
            k--;
        }
        if (stk.empty())
            return "0";
        string ans = "";
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        while (!ans.empty() && ans.back() == '0')
            ans.pop_back();
        if (ans.empty())
            return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
