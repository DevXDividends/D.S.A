// TC: O(nlogn) SC: O(n)​
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        
        if(!root)return {};
        vector<int> ans;
        queue<pair<Node*,int>> q;
        map<int,int> mpp;
        q.push({root,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int line = it.second;
            mpp[line] = it.first->data;
            
            if(it.first->left) 
                q.push({it.first->left,line-1});
                
            if( it.first->right)
                q.push({it.first->right,line+1});
            
        }
        for(auto &r:mpp) 
            ans.emplace_back(r.second);
        
        return ans;
    }
};​
