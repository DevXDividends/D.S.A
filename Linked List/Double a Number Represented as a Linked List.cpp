// brute TC:O(n) SC:O(n)
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
    ListNode* doubleIt(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* temp = head;
        stack<int> stk;
        while (temp) {
            stk.push(temp->val);
            temp = temp->next;
        }
        ListNode* newHead=nullptr;
        int carry = 0;
        while (!stk.empty()) {
            long long mul = stk.top() * 2 + carry;
            stk.pop();
            ListNode* nn = new ListNode(mul % 10);
            carry = mul / 10;
            nn->next = newHead;
            newHead = nn;
        }
        if (carry) {
            ListNode* nn = new ListNode(carry);
            nn->next = newHead;
            newHead = nn;
        }
        return newHead;
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
    ListNode* doubleIt(ListNode* head) {
        if (!head)
            return nullptr;
        head = reverseList(head);
        ListNode* temp = head;
        int carry = 0;
        while (temp) {
            int mul = temp->val * 2 + carry;
            temp->val = mul % 10;
            carry = mul / 10;
            if (!temp->next && carry) {
                ListNode* nn = new ListNode(carry);
                temp->next = nn;
                carry = 0;
                break;
            }
            temp = temp->next;
        }

        return reverseList(head);
    }
};
