// TC:O(n) SC:O(n)
/*
class Node {
 public:
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
    int lengthOfLoop(Node *head) {
        // code here
        if(!head)return 0;
        int cnt=0;
        unordered_map<Node*,int> mpp;
        Node* temp=head;
        while(temp){
            if(mpp.find(temp)!=mpp.end()){
                return cnt-mpp[temp];
            }
            mpp[temp]=cnt++;
            temp=temp->next;
        }
        return 0;
    }
};
// TC:O(n) SC:O(1)
/*
class Node {
 public:
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
    int lengthOfLoop(Node *head) {
        // code here
        if(!head)return 0;
        Node* slow=head;
        Node* fast=head;
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                int cnt=1;
                fast=fast->next;
                while(fast!=slow){
                    cnt++;
                    fast=fast->next;
                }
                return cnt;
                
            }
        }
        return 0;
    }
};
