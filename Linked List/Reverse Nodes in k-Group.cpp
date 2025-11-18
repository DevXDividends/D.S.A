// TC:O(2n) SC:O(1)
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
    ListNode* getKthNode(ListNode* head, int k) {
        ListNode* temp = head;
        while (temp && k > 1) {
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        while (temp) {

            ListNode* kthNode = getKthNode(temp, k);
            if (!kthNode) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;
        
            reverseList(temp);
            if (temp == head)
                head = kthNode;
            else
                prevNode->next = kthNode;
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
