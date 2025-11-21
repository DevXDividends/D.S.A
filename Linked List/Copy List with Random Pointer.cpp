// brute force TC:O(n) SC:O(n)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        Node* temp=head;
        unordered_map<Node*,Node*> mpp;
        while(temp){
            Node* newNode=new Node(temp->val);
            mpp[temp]=newNode;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            Node* copyNode=mpp[temp];
            copyNode->next=mpp[temp->next];
            copyNode->random=mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
    }
};
// optimal TC:O(3n) SC:O(n) 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
void copyList(Node* &head){
    Node* temp=head;
    while(temp){
        Node* newNode= new Node(temp->val);
        newNode->next=temp->next;
        temp->next=newNode;
        temp=temp->next->next;
    }
}
void connectRandomPointers(Node* &head){
    Node* temp=head;
    while(temp){
        Node* copyNode=temp->next;
        if(temp->random)
           copyNode->random=temp->random->next;
           else
           copyNode->random=nullptr;
        temp=temp->next->next;
    }
} 
Node* getExtractedList(Node* &head){
    Node* dummy=new Node(-1);
    Node* res=dummy;
    Node* temp=head;
    while(temp){
        res->next=temp->next;
        temp->next=temp->next->next;
        temp=temp->next;
        res=res->next;
    }
    return dummy->next;
}
    Node* copyRandomList(Node* head) {
       if(!head)return nullptr;
       copyList(head);
       connectRandomPointers(head);
       return getExtractedList(head);
    }
};
