// TC:O(n) SC:O(n) 
class Solution {
    private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* prev;
    TreeNode* last;
    private:
    void inorder(TreeNode* root){
        if(!root)return;

        // left;
        inorder(root->left);
        // business
        if(prev!=nullptr && (root->val<prev->val)){
            // check if it is first
            if(!first){
                first = prev;
                middle = root;
            }else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);


    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle)swap(first->val,middle->val);
    }
};
