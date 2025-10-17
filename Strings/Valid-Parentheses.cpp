class Solution {
public:
    bool check(char first, char sec) {
        return (first == '(' && sec == ')') || (first == '[' && sec == ']') ||
               (first == '{' && sec == '}');
    }
    bool isValid(string s) {
        if (s == "")
            return true;
        if (s.length() == 1)
            return false;
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (stk.empty() ||!check(stk.top(), c)) {
                    return false;
                }
                stk.pop();
            }
        }return stk.empty();
    }
};
