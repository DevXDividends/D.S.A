// brute force TC:O(n x k) +O(m log m)  + O(m) SC:O(m) + O(m)
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp) {
                ans.emplace_back(temp->val);
                temp = temp->next;
            }
        }
        sort(ans.begin(), ans.end());
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        for (int n : ans) {
            ListNode* nn = new ListNode(n);
            temp->next = nn;
            temp = nn;
        }
        return dummy->next;
    }
};
// better TC:O(n^3) SC:O(1)

class Solution {
public:
    ListNode* mergeLists(ListNode*& head1, ListNode*& head2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
        curr->next = (head1 != nullptr) ? head1 : head2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()<1)return nullptr;
        int n = lists.size();
        ListNode* head1 = lists[0];
        for (int i = 1; i < n; i++) {
            head1 = mergeLists(head1, lists[i]);
        }
        return head1;
    }
};
// optimal TC:O(Nlogk)  SC:O(k)
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode dummy(-1);
        ListNode* curr = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            curr->next = node;
            curr = curr->next;

            if (node->next)
                pq.push(node->next);
        }

        return dummy.next;
    }
};
