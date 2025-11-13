// TC:O(3n) SC:O(1)
/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node* reverse(Node* &head){
      Node* curr=head;
      Node* prev=nullptr;
      while(curr){
          Node * next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
      }
      return prev;
  }
    Node* addOne(Node* head) {
        // Your Code here
     
        if(!head)return head;
      
        head=reverse(head);
        
        Node* temp=head;
        int carry=1;
        while(temp){
            temp->data=temp->data+carry;
            if(temp->data<10){
                carry=0;
                break;
            }else{
                carry=1;
            }
           
            if(!temp->next)break;
            temp=temp->next;
            
        }
        if(carry){
            temp->next=new Node(carry);
        }
        
        return reverse(head);
        
        // return head of list after adding one
    }
};
// TC:O(n) SC:O(n)
/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  int addNum(Node* &temp){
      if(!temp)return 1;
      int carry=addNum(temp->next);
      temp->data+=carry;
      if(temp->data<10)
          return 0;
      
      temp->data=0;
      return 1;
      
  }
    Node* addOne(Node* head) {
        // Your Code here
        int carry=addNum(head);
        if(carry){
            Node* nn=new Node(1);
            nn->next=head;
            return nn;
        }
        return head;
        
    }
};
