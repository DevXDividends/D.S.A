// TC:O(max(n, m)) SC:O(max(n, m))
/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  Node* reverseList(Node* head){
      Node* curr=head;
      Node* next=head;
      Node* prev=nullptr;
      while(curr){
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
      }
      return prev;
  }
  Node* trimZeros(Node* head){
      while(head && head->data==0){
          head=head->next;
      }
      return head;
  }
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        head1=trimZeros(head1);
        head2=trimZeros(head2);
        
        head1=reverseList(head1);
        head2=reverseList(head2);
        
        Node* t1=head1;
        Node* t2=head2;
        
        Node* dummy=new Node(-1);
        Node* curr=dummy;
        int carry=0;
        while(t1!=NULL || t2!=NULL || carry){
           int sum=carry;
            if(t1) sum+=t1->data;
            if(t2)sum+=t2->data;
            Node* nn= new Node(sum%10);
            curr->next=nn;
            curr=curr->next;
            carry=sum/10;
            if(t1)t1=t1->next;
            if(t2)t2=t2->next;
        }
       
        return reverseList(dummy->next);
        
    }
};
