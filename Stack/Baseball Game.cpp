// TC:O(2n) SC:O(n) 
class Solution {
public:
    int calPoints(vector<string>& s) {
        stack<int> stk;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != "C" && s[i] != "D" && s[i] != "+")
                stk.push(stoi(s[i]));
            else if (s[i] == "+") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.push(a);
                stk.push(a + b);
            } else if (s[i] == "D") {
                stk.push(stk.top() * 2);
            } else if (s[i] == "C")
                stk.pop();
        }
        int sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};
