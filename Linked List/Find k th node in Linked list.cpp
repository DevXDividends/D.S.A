//TC:O(n) SC:O(1)
class Solution {
  public:
    int fractional_node(struct Node *head, int k) {
        // your code here
        if(!head)return -1;
        int n=1;
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
            n++;
        }
        n=(n + k - 1) / k;
        int cnt=1;
        temp=head;
        while(temp){
            if(cnt==n)return temp->data;
            temp=temp->next;
            cnt++;
        }
        return -1;
    }
};
