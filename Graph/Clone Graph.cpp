// TC:O(V + E) SC:O(V)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mpp) {
        if (node == nullptr)
            return nullptr;

        if (mpp.count(node))
            return mpp[node];

        Node* newNode = new Node(node->val);
        mpp[node] = newNode;
        for (Node* neigh : node->neighbors) {
            newNode->neighbors.emplace_back(dfs(neigh, mpp));
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<Node*, Node*> mpp;
        return dfs(node, mpp);
    }
};
