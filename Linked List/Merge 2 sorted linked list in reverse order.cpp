// Brute Force
// TC = O(k log k) SC = O(k)
class Solution {
public:
    Node* mergeResult(Node* head1, Node* head2) {
        priority_queue<int> pq;
        Node* temp = head1;

        while (temp) {
            pq.push(temp->data);
            temp = temp->next;
        }

        temp = head2;
        while (temp) {
            pq.push(temp->data);
            temp = temp->next;
        }

        Node* dummy = new Node(-1);
        temp = dummy;

        while (!pq.empty()) {
            temp->next = new Node(pq.top());
            pq.pop();
            temp = temp->next;
        }

        return dummy->next;
    }
};



// optimal
// TC = O(n1 + n2) SC = O(1)
class Solution {
public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        while (head) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    Node* mergeResult(Node* head1, Node* head2) {
        Node dummy(-1);
        Node* curr = &dummy;

        while (head1 && head2) {
            if (head1->data <= head2->data) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }

        curr->next = (head1 != nullptr) ? head1 : head2;

        return reverseList(dummy.next);
    }
};


