// TC:O(2n) SC:O(n)
"""
class Node:
    def __init__(self, val):
        self.data = val
        self.next = None
        self.prev = None
"""

class Solution:
    def reverse(self, head):
        # code here
        stack=[]
        temp=head
        while temp:
            stack.append(temp.data)
            temp=temp.next
        temp=head
        while temp:
            temp.data=stack.pop()
            temp=temp.next
        return head
        
//TC:O(n) SC:O(1)
"""
class Node:
    def __init__(self, val):
        self.data = val
        self.next = None
        self.prev = None
"""

class Solution:
    def reverse(self, head):
        if not head:return None
        if not head.next:return head
        current=head
        last=None
        while current:
            last=current.prev
            current.prev=current.next
            current.next=last
            current=current.prev
        
        return last.prev
        
        
