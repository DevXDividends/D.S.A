// brute TC:
push() → O(1)
pop() → O(n)
top() → O(n)
empty() → O(1)

SC:O(2n)

class MyStack {
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) { q1.push(x); }

    int pop() {
        while (q1.size() > 1) { // pop all the elements  and add them onto 2nd
                                // queue until the last one
            q2.push(q1.front());
            q1.pop();
        }
        int topEle = q1.front();
        q1.pop();
        swap(q1, q2);
        return topEle;
    }

    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int ele = q1.front();
        q2.push(ele);
        q1.pop();
        swap(q1, q2);
        return ele;
    }

    bool empty() { return q1.empty(); }
};


// slight better sol TC:
push() → O(1)
pop() → O(n)
top() → O(1)
empty() → O(1)

SC:O(2n)

class MyStack {
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) { q1.push(x); }

    int pop() {
        while (q1.size() > 1) { // pop all the elements  and add them onto 2nd
                                // queue until the last one
            q2.push(q1.front());
            q1.pop();
        }
        int topEle = q1.front();
        q1.pop();
        swap(q1, q2);
        return topEle;
    }

    int top() {
        return q1.back();
    }

    bool empty() { return q1.empty(); }
};

// optimal TC:
push() → O(n)
pop() → O(1)
top() → O(1)
empty() → O(1)

SC:O(n)
class MyStack {
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int n = q.size();
        for (int i = 1; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int ele = q.front();
        q.pop();
        return ele;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
};

