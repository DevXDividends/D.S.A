// TC: O(n) SC:O(n)
class Solution {
  public:
   bool isLeaf(Node* root){
       return root->left == nullptr && root->right==nullptr;
   }
    bool isSumProperty(Node *root) {
        if(!root)return true;
        int sum = 0;
        if(root->left) sum+=root->left->data;
        if(root->right)sum+=root->right->data;
        if(sum != root->data && !isLeaf(root)  )return false;
        else return isSumProperty(root->left) && 
                    isSumProperty(root->right);
        
    }
};
