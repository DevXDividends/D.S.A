/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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