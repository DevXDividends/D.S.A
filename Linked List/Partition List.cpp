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
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return nullptr;
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* l1 = dummy1;
        ListNode* l2 = dummy2;
        ListNode* temp = head;
        while (temp) {
            if (temp->val < x) {
                l1->next = temp;
                l1 = l1->next;
            } else {
                l2->next = temp;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        l2->next = nullptr;
        l1->next = dummy2->next;
        return dummy1->next;
    }
};
