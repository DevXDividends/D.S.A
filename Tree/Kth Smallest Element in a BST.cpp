// TC:O(N) SC:O(1)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt =0;
        int ans=-1;
        TreeNode* curr = root;
        while(curr){
            if(!curr->left){
                cnt++;
                if(cnt==k)ans = curr->val;
                curr=curr->right;
            }else{
                TreeNode* trav = curr->left;
                while(trav->right && trav->right!=curr)
                    trav=trav->right;
                if(trav->right==nullptr){
                    trav->right = curr;
                    curr=curr->left;
                }else{
                    cnt++;
                    if(cnt == k)ans = curr->val;
                    trav->right=nullptr;
                    curr=curr->right;
                }
            }
            
        }
        return ans;
    }
};
