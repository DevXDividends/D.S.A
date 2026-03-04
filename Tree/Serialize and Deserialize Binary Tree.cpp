// TC:O(n) SC:O(n) 

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node)
                str.append("#,");
            else
                str.append(to_string(node->val) + ',');
            if (node) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return nullptr;

        queue<TreeNode*> q;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        if (str == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#") {
                node->left = nullptr;
            } else {
                TreeNode* n = new TreeNode(stoi(str));
                node->left = n;
                q.push(n);
            }
            getline(s, str, ',');
            if (str == "#") {
                node->right = nullptr;
            } else {
                TreeNode* n = new TreeNode(stoi(str));
                node->right = n;
                q.push(n);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
