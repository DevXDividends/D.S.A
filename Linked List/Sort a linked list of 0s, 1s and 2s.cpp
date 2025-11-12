// TC:O(n) SC:O(1)
/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int cnt0=0,cnt1=0,cnt2=0;
        Node* temp=head;
        while(temp){
            if(temp->data==0)cnt0++;
            else if(temp->data==1)cnt1++;
            else cnt2++;
            temp=temp->next;
        }
        temp=head;
        while(temp){
           if(cnt0>0){
               temp->data=0;
               cnt0--;
           }else if(cnt1>0){
               temp->data=1;
               cnt1--;
           }else{
               temp->data=2;
               cnt2--;
           }
           temp=temp->next;

        }
        return head;

        
        
    }
};
// TC:O(n) SC:O(1)
/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(!head || !head->next)return head;
        Node* zeroHead=new Node(-1);
        Node* zero=zeroHead;
        Node* oneHead=new Node(-1);
        Node* one=oneHead;
        Node* twoHead=new Node(-1);
        Node*  two=twoHead;
        Node* temp=head;
        while(temp){
            if(temp->data==0){
                zero->next=temp;
                zero=zero->next;
            }else if(temp->data==1){
                one->next=temp;
                one=one->next;
            }else{
                two->next=temp;
                two=two->next;
            }
            temp=temp->next;
        }
    zero->next=(oneHead->next)?oneHead->next:twoHead->next;
    one->next=twoHead->next;
    two->next=nullptr;
    Node* newHead=zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
        

    }
};
