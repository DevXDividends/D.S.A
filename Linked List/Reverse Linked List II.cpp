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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* beforeRev = dummy;
        for (int i = 0; i < left-1; i++) 
            beforeRev = beforeRev->next;
        
        ListNode* revHead = beforeRev->next;
        ListNode* curr=revHead;
        ListNode* prev=beforeRev;
        for(int i=0;i<right-left+1;i++){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        revHead->next=curr;
        beforeRev->next=prev;
        return dummy->next;

    }
};
