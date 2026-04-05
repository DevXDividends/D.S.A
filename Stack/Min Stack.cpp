// approach 1 : TC:O(1) SC:O(2 * n) because of pair<>
class MinStack {
public:
    stack<pair<int,int>> stk;
    MinStack() {
        
    }
    bool isEmpty(){
        return stk.empty();
    }
    void push(int val) {
        if(isEmpty())
            stk.push({val,val});
        else if(stk.top().second<val)
            stk.push({val,stk.top().second});
        else
           stk.push({val,val});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

// approach  2 TC:O(1) SC:O(n) 
class MinStack {
    long long currentMin;
    stack<long long> stk;

public:
    MinStack() {
        currentMin = LLONG_MAX;
    }

    bool isEmpty() {
        return stk.empty();
    }

    void push(int val) {
        long long x = val;

        if (isEmpty()) {
            stk.push(x);
            currentMin = x;
        } else {
            if (x > currentMin) {
                stk.push(x);
            } else {
                stk.push(2 * x - currentMin);  // safe now
                currentMin = x;
            }
        }
    }

    void pop() {
        if (isEmpty()) return;

        long long top = stk.top();
        stk.pop();

        if (top < currentMin) {
            currentMin = 2 * currentMin - top;
        }
    }

    int top() {
        long long top = stk.top();

        if (top < currentMin)
            return (int)currentMin;

        return (int)top;
    }

    int getMin() {
        return (int)currentMin;
    }
};
