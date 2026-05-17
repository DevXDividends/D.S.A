TC:O(n) SC:O(n) 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (int ast : asteroids) {
            bool destroyed = false;
            while (!stk.empty() && (stk.top() > 0 && ast < 0)) {
                if (stk.top() < abs(ast)) {
                    stk.pop();
                    continue;
                } else if (stk.top() > abs(ast)) {
                    destroyed = true;
                    break;
                } else {
                    stk.pop();
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed)
                stk.push(ast);
        }
        vector<int> ans(stk.size());
        int i = stk.size() - 1;

        while (!stk.empty()) {
            ans[i--] = stk.top();
            stk.pop();
        }
        return ans;
    }
};
