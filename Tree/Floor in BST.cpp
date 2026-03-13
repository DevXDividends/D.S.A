// TC:o(log n) SC:O(1)
class Solution {
  public:
    int findFloor(Node* root, int x) {
        if(!root)return -1;
        int value=-1;
        while(root){
            if(x == root->data){
                value  = root->data;
                return value;
            }
            if(x > root->data){
                value = root->data;
                root=root->right;
            }else
                root=root->left;
            
            
        }
        return value;
        
    }
};
