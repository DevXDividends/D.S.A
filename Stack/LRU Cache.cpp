// TC:O(1)  SC:O(capacity)
class Node {
public:
    int key, value;
    Node* next;
    Node* prev;

public:
    Node(int k, int v) {
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache {
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mpp;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
        mpp.clear();
    }
    void deleteNode(Node* node) {
        Node* nextNode = node->next;
        Node* prevNode = node->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void insertAfterHead(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->next = nextNode;
        nextNode->prev = node;
        node->prev = head;
    }
    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if (mpp.size() == capacity) {
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
