// TC:O(n) SC:O(K)
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        
        int  n  = q.size();
        if(k>n)return q;
        stack<int> st;
        for(int i=0;i<k;i++){
            st.push(q.front());
            q.pop();
        }
        int n2 =q.size();
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        for(int i=0;i<n2;i++){
            q.push(q.front());
            q.pop();
        }
        return q;
        
    }
};
