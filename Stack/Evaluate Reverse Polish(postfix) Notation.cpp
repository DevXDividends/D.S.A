// TC:O(n) SC:O(n)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string c : tokens) {
            // operand
            if (isdigit(c[0]) || (c.size()>1 && c[0] == '-'))
                stk.push(stoi(c));
            else {
                int b = stk.top(); stk.pop();
                int a = stk.top();
                stk.pop();
                
                if (c == "+")
                    stk.push(a + b);
                else if (c == "-")
                    stk.push(a - b);
                else if (c == "*")
                    stk.push(a * b);
                else if (c == "/")
                    stk.push(a / b);
            }
        }
        return stk.top();
    }
};
