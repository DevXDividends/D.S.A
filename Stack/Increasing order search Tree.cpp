// approach 1
class Solution {
public:
void inorder(TreeNode* root,stack<TreeNode*>&stk){
    if(!root)return;
    
    inorder(root->right,stk);
    stk.push(root);
    inorder(root->left,stk);
}
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> stk;
        inorder(root,stk);
        
       TreeNode* node= new TreeNode(-1); 
       TreeNode* curr= node;
       while(!stk.empty()){
           TreeNode* nn=new TreeNode (stk.top()->val);
           stk.pop();
           curr->right=nn;
           curr=nn;
           
       }
       return node-> right;
    }
};
// approach 2

class Solution {
    TreeNode* curr;
public:
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        root->left = nullptr;
        curr->right = root;
        curr = root;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        curr = dummy;
        inorder(root);
        return dummy->right;
    }
};
