// brute TC:O(1) SC:O(n)
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
    vector<int> vec;
    Solution(ListNode* head) {
        ListNode* curr = head;
        while (curr) {
            vec.emplace_back(curr->val);
            curr = curr->next;
        }
    }

    int getRandom() { return vec[rand() % vec.size()]; }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

// optimal TC:O(1) SC:O(1)
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
    ListNode* head;
    Solution(ListNode* head) { this->head = head; }

    int getRandom() {
        int result = 0;
        ListNode* curr = head;
        int i = 1;
        while (curr) {
            if (rand() % i == 0)
                result = curr->val;
            i++;
            curr = curr->next;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
