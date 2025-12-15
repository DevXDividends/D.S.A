class Solution {
public:
    int height(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    // Right Rotation (LL)
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        // update heights (BOTTOM UP)
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    // Left Rotation (RR)
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        // update heights (BOTTOM UP)
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* insertToAVL(Node* node, int data) {
        // Normal BST insert
        if (!node)
            return new Node(data);

        if (data < node->data)
            node->left = insertToAVL(node->left, data);
        else if (data > node->data)
            node->right = insertToAVL(node->right, data);
        else
            return node; // duplicates not allowed

        // Update height
        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // LL
        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        // RR
        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        // LR
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL
        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
};
