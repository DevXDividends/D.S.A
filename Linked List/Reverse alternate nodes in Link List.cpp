// TC:O(n) SC:O(1)
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element
  Node is defined as
  struct Node
  {
      int data;
      struct Node *next;

      Node(int x){
        data = x;
        next = NULL;
      }

   };

*/
class Solution {
  public:
   Node* reverseList(Node* &head){
      Node* curr=head;
      Node* prev=nullptr;
      while(curr){
          Node* next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
      }
      return prev;
   }
    void rearrange(Node* head) {
        if(!head)return;
        Node* org=head;
        Node* arr=head->next;
        Node* arrHead=head->next;
        while(arr && arr->next){
            org->next=arr->next;
            org=org->next;
            arr->next=org->next;
            arr=arr->next;
        }
        arrHead=reverseList(arrHead);
        org->next=arrHead;
    }
};
