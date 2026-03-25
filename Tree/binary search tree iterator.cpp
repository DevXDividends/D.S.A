// Tc :O(1) SC:O(h)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> stk;

public:
    BSTIterator(TreeNode* root) { pushAll(root); }

    int next() {
        TreeNode* topNode = stk.top();
        stk.pop();
        pushAll(topNode->right);
        return topNode->val;
    }

    bool hasNext() { return !stk.empty(); }
    void pushAll(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }
};

// TC:O(1)average SC:O(1)

class BSTIterator {
    TreeNode* curr;

public:
    BSTIterator(TreeNode* root) { curr = root; }

    int next() {
        int ans;
        while (curr) {
            if (!curr->left) {
                ans = curr->val;
                curr = curr->right;
                return ans;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr)
                    prev = prev->right;
                if (!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    ans=curr->val;
                    prev->right = nullptr;
                    curr = curr->right;
                    return ans;
                }
            }
        }
        return -1;
    }

    bool hasNext() { return curr != nullptr; }
};


