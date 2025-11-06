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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr)
            return head;
        int len = 1;
        ListNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
            len++;
        }
        k %= len;
        if (k == 0)
            return head;
        curr->next = head;
        curr = head;
        for (int i = 0; i < len-k-1; i++)
            curr = curr->next;

        head = curr->next;
        curr->next=nullptr;
        return head;
    }
};
