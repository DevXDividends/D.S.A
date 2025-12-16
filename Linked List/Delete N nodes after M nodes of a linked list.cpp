// TC:O(n) SC:O(1)
/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        if(!head)return nullptr;
       Node* curr=head;
       Node* prev=nullptr;
       while(curr){
           for(int i=0;i<m && curr;i++){
               prev=curr;
               curr=curr->next;
           }
           for(int i=0;i<n && curr;i++){
               Node* delNode=curr;
               curr=curr->next;
               delete delNode;
           }
           prev->next=curr;
       }
       return head;
        
        return head;
    }
};
