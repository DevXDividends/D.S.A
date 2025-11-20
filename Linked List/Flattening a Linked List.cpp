// TC:O(n * k) SC:O(1)
/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
  Node* merge(Node* head1,Node* head2){
      Node* dummy=new Node(-1);
      Node* res=dummy;
      Node* l1=head1;
      Node* l2=head2;
      while(l1 && l2){
          if(l1->data<=l2->data){
              res->bottom=l1;
              res=l1;
              l1=l1->bottom;
          }else{
              res->bottom=l2;
              res=l2;
              l2=l2->bottom;
          }
          res->next=nullptr;
      }
      if(l1)
          res->bottom=l1;
      
      if(l2)res->bottom=l2;
      return dummy->bottom;
  }
  Node* goDeep(Node* &root){
      if(!root || !root->next)return root;
      Node* mergedHead=goDeep(root->next);
      return merge(root,mergedHead);
  }
    Node *flatten(Node *root) {
        // code here
        return goDeep(root);
    }
};
