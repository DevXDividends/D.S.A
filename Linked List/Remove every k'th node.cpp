// TC: O(n) SC:O(1)
/* Link list Node

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

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */
class Solution {
  public:
    Node* deleteK(Node* head, int k) {
        // code here
        if(!head)return nullptr;
        Node* dummy=new Node(0);
        dummy->next=head;
        Node* curr=head;
        Node* prev=dummy;
        
        int cnt=1;
        while(curr){
            if(cnt%k==0){
                Node* temp=curr;
                curr=curr->next;
                prev->next=temp->next;
                delete temp;
            }else{
                prev=curr;
                curr=curr->next;
            }
            cnt++;

        }
        Node* newhead=dummy->next;
        delete dummy;
        return newhead;
    }
};
