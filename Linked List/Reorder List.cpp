// Brute force: TC:O(n^2) SC:O(1)
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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
        ListNode* curr = head;
        while (curr->next) {
            ListNode* temp = curr->next;
            while (temp->next && temp->next->next) {
                temp = temp->next;
            }
            if (!temp->next)
                return;
            ListNode* nn = temp->next;
            temp->next = nullptr;
            nn->next = curr->next;
            curr->next = nn;
            curr = curr->next->next;
        }
    }
};
// optimal TC:O(n) SC:O(1)
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
    ListNode* reverseList(ListNode*& head) {
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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nextList = slow->next;
        slow->next = nullptr;
        nextList = reverseList(nextList);

        ListNode* curr = nextList;
        ListNode* temp = head;
        while (curr) {
            ListNode* nn = curr;
            curr = curr->next;
            nn->next = temp->next;
            temp->next = nn;
            temp = temp->next->next;
        }
    }
};
