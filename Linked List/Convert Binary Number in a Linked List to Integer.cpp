// TC :O(n) SC:O(n)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if (!head)
            return -1;
        vector<int> vec;
        ListNode* temp = head;
        while (temp) {
            vec.emplace_back(temp->val);
            temp = temp->next;
        }
        int n = vec.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (vec[i] * pow(2, n - i - 1));
        }
        return ans;
    }
};
// TC:O(n) SC:O(1)

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(!head)return -1;
        ListNode* temp=head;
        int n=0;
        while(temp){
            temp=temp->next;
            n++;
        }
        int ans=0;
        temp=head;
        while(temp){
            ans+=(temp->val * pow(2,--n));
            temp=temp->next;
        }
        return ans;
    }
};
