// TC:o(m+n) SC:O(m)
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA)
            return nullptr;
        if (!headB)
            return nullptr;
        ListNode* temp = headA;
        unordered_set<ListNode*> mpp;
        while (temp) {
            mpp.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp) {
            if (mpp.find(temp) != mpp.end()) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};
// TC:O(n+m) SC:O(1)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if (!headA || !headB)
            return NULL;
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=b){
            a=a?a->next:headB;
            b=b?b->next:headA;
        }
        return a;
    }
};
