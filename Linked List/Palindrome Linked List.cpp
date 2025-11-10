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
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        ListNode* temp=head;
        while(temp){
            stk.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(temp->val!=stk.top())return false;
            stk.pop();
            temp=temp->next;
        }
        return true;
        
    }
};
