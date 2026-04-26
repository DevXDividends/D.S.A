// TC:O(2n) SC:O(n) 
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void reverse(vector<int> &arr) {
        int i = 0;
        int j = arr.size() - 1;
        while (i < j)
            swap(arr[i++], arr[j--]);
    }
    vector<int> postorder(Node* root) {
        if (!root) return {};
        stack<Node*> stk;
        stk.push(root);
        vector<int> ans;
        while (!stk.empty()) {
            Node* n = stk.top();
            stk.pop();
            ans.emplace_back(n->val);
            if (n->children.size() > 0)
                for (int i = 0; i < n->children.size(); i++)
                    stk.push(n->children[i]);
        }
        reverse(ans);
        return ans;
    }
};
