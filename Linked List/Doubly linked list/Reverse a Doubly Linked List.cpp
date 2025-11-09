// TC:O(2n) SC:O(n)
/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        stack<int> stk;
        Node* temp=head;
        while(temp!=nullptr){
            stk.push(temp->data);
            temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr){
            temp->data=stk.top();
            stk.pop();
            temp=temp->next;
        }
        return head;
    }
};

// TC:O(n) SC:O(1)
/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(!head )return nullptr;
        if(!head->next)return head;
        Node* current=head;
        Node* last=nullptr;
        while(current){
            last=current->prev;
            current->prev=current->next;
            current->next=last;
            current=current->prev;
        }
        return last->prev;
    }
};
