// TC:O(n) SC:O(1)
/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        int cnt=1;
        Node* curr=head;
        while(curr){
            if(cnt==x)break;
            cnt++;
            curr=curr->next;
        }
        Node*prev=curr->prev;
        Node* front=curr->next;
        if(prev==nullptr && front==nullptr)return nullptr;
        else if(prev==nullptr){
            curr->next=nullptr;
            front->prev=nullptr;
            delete curr;
            return front;
        }else if(front==nullptr){
            curr->prev=nullptr;
            prev->next=nullptr;
            delete curr;
            return head;
        }
        prev->next=front;
        front->prev=prev;
        curr->next=nullptr;
        curr->prev=nullptr;
        delete curr;
        return head;
    }
};
