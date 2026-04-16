// brute TC:
push() -> O(1)
pop() -> O(2n)
peek() -> O(2n)
empty() -> O(1)

SC:O(2n)
class MyQueue {
    stack<int> stk1, stk2;

public:
    MyQueue() {}

    void push(int x) { stk1.push(x); }

    int pop() {
        while (stk1.size() > 1) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        int ele = stk1.top();
        stk1.pop();
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ele;
    }

    int peek() {
        while (stk1.size() > 1) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        int ele = stk1.top();
        stk2.push(ele);
        stk1.pop();
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ele;
    }

    bool empty() { return stk1.empty(); }
};
// optimal TC:
push() -> O(1)
pop() -> O(n)
peek() -> O(n)
empty() -> O(1)

SC:O(n)
class MyQueue {
    stack<int> stk;

public:
    MyQueue() {}

    void push(int x) { stk.push(x); }

    int pop() {
        if (stk.size() == 1) {
            int x = stk.top();
            stk.pop();
            return x;
        }
        int top = stk.top();
        stk.pop();
        int res = pop();
        stk.push(top);
        return res;
    }

    int peek() {
        if (stk.size() == 1) {
            return stk.top(); // don't pop
        }

        int top = stk.top();
        stk.pop();

        int res = peek();

        stk.push(top);

        return res;
    }

    bool empty() { return stk.empty(); }
};


