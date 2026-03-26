// approach 1 TC:O(n) SC:O(n) 
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root)
            return;

        inorder(root->left, arr);
        arr.emplace_back(root->val);
        inorder(root->right, arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        int i = 0;
        int j = arr.size() - 1;
        while (i < j) {
            int sum = arr[i]+arr[j];
            if (sum == k)
                return true;
            if (sum < k)
                i++;
            else
                j--;
        }
        return false;
    }
};


// approach 2 TC:O(n) SC:O(h) 

class BSTIterator {
private:
    stack<TreeNode*> stk;
    // isreverse = true-> push right
    // isreverse = false ->push left
    bool isreverse = true;

public:
    BSTIterator(TreeNode* root, bool isrev) {
        isreverse = isrev;
        pushALL(root);
    }
    bool hasNext(){
        return !stk.empty();
    }
    int next() {
        TreeNode* topVal = stk.top();
        stk.pop();
        if (isreverse)
            pushALL(topVal->right);
        else
            pushALL(topVal->left);
        return topVal->val;
    }
    void pushALL(TreeNode* root) {
        while (root) {
            stk.push(root);
            if (isreverse)
                root = root->right;
            else
                root = root->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while (r.hasNext() && l.hasNext() && i < j) {
            if (i + j == k)
                return true;
            if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};
