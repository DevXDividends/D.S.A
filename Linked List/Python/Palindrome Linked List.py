// TC:O(n) SC:O(n)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        stack=[]
        temp=head
        while temp:
            stack.append(temp.val)
            temp=temp.next
        temp=head
        while temp:
            if temp.val != stack[-1]:return False
            stack.pop()
            temp=temp.next
        return True

// TC:O(n) SC:O(1)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow=head
        fast=head
        while(fast  and fast.next):
            slow=slow.next
            fast=fast.next.next
        prev=None
        curr=slow
        while curr:
            next=curr.next
            curr.next=prev
            prev=curr
            curr=next
        first=head
        second=prev
        while first and second:
            if first.val != second.val:return False
            first=first.next
            second=second.next
        return True
        
