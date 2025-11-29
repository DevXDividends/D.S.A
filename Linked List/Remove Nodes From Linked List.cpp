// TC:O(n) SC:O(n)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head)return nullptr;
        stack<ListNode*> stk;
        for(ListNode* temp=head;temp!=nullptr; temp=temp->next){
            while(!stk.empty() && stk.top()->val<temp->val)stk.pop();
            stk.push(temp);
        }
        ListNode* newHead=nullptr;
        while(!stk.empty()){
            ListNode* curr=stk.top();
            stk.pop();
            curr->next=newHead;
            newHead=curr;
        }
        return newHead;
    }
};
// TC:O(n) SC:O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if (!head)
            return nullptr;
        head = reverseList(head);

        int maxVal = head->val;
        ListNode* curr = head->next;
        ListNode* prev = head;
        while (curr) {
            if (curr->val < maxVal) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                maxVal = curr->val;
                prev = curr;
                curr = curr->next;
            }
        }
        return reverseList(head);
    }
};
