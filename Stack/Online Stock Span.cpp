// brute TC:O(n^2) SC:O(n)
class StockSpanner {
    private:
    stack<int> stk;
    stack<int> helperstk;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        bool popped = false;
        while(!stk.empty() && stk.top() < price){
            helperstk.push(stk.top());stk.pop();
            popped = true;
            cnt++;
        }
        stk.push(price);
        if(popped){
            while(!helperstk.empty()){
            stk.push(helperstk.top());helperstk.pop();
            }
        }
        return cnt;
    }
};
// optimised TC:O(n) SC:O(n)
class StockSpanner {
    stack<pair<int, int>> stk;

public:
    StockSpanner() {}

    int next(int price) {
        int cnt = 1;
        while (!stk.empty() && stk.top().first <= price) {
            cnt += stk.top().second;
            stk.pop();
        }
        stk.push({price,cnt});
        return cnt;
    }
};
