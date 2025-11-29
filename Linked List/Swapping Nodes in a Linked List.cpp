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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head)
            return nullptr;
        ListNode* first = head;
        int cnt = 1;

        while (cnt != k) {
            first = first->next;
            cnt++;
        }
        ListNode* second=head;
        ListNode* temp=first;
        while(temp->next){
            temp=temp->next;
            second=second->next;
        }
        swap(first->val,second->val);
        return head;
    }
};
