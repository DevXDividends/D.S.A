// TC:O(n) SC:O(n) 
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
    TreeNode* build(vector<int> &a,int &i,int bound){
        if(i == a.size() || a[i]>bound)return nullptr;
        TreeNode* root = new TreeNode(a[i++]);
        root->left = build(a,i,root->val);
        root->right  = build(a,i,bound);
        return root;
    }
};
