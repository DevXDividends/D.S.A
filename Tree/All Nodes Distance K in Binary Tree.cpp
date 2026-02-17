// TC:O(n) SC:O(n) 
class Solution {
public:
   void markParent(TreeNode* root, unordered_map<TreeNode* ,TreeNode*> &parent){
    if(root==nullptr)return;
     queue<TreeNode*> q;
     q.push(root);
     while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node->left){
            parent[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            parent[node->right]  =  node;
            q.push(node->right);
        }
     }
   } 
    queue<TreeNode*> findNodesAtDistance(TreeNode* target,unordered_map<TreeNode* ,TreeNode*> &parent,int k){
        queue<TreeNode*> q;
        unordered_map<TreeNode* ,bool> visited;

        q.push(target);
        visited[target] = true;
        int distance = 0;
        while(!q.empty()){
            int size = q.size();
            int flag = false;
            if(distance == k)break;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    visited[node->left] = true;
                    q.push(node->left);
                    flag = true;
                }
                if(node->right && !visited[node->right]){
                    visited[node->right] = true;
                    q.push(node->right);
                    flag = true;
                }
                if(parent[node] && !visited[parent[node]]){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                    flag = true;
                }

            }
             distance++;
        }
        return q;

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode*> parent;
        markParent(root,parent);
        queue<TreeNode*> q = findNodesAtDistance(target,parent,k);
        vector<int> answers;
        while(!q.empty()){
            answers.emplace_back(q.front()->val);
            q.pop();
        }
        return answers;
    }
};
