// TC:O(n) SC:O(n) 
class Solution {
  public:
    vector<int> leftView(Node *root) {
        if(!root)
            return {};
        vector<int> ans;
        queue<pair<Node*,int>> q;
        map<int,int> mpp;
        q.push({root,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.second;
            
            mpp[row] = it.first->data;
            
            if(it.first->right)
                q.push({it.first->right,row+1});
                
            if(it.first->left) 
                q.push({it.first->left,row+1});
        }
        for(auto &it:mpp)
            ans.emplace_back(it.second);
        return ans;
        
    }
};
