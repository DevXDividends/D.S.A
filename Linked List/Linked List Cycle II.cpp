// TC:O(n) SC:O(n)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)return nullptr;
        unordered_set<ListNode*> mpp;
        ListNode* temp=head;
        while(temp){
            if(mpp.find(temp)!=mpp.end()){
                return temp;
            }
            mpp.insert(temp);
            temp=temp->next;
        }
        return nullptr;
    }
};
// TC:O(n) SC:O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow && fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* entry = head;
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};
