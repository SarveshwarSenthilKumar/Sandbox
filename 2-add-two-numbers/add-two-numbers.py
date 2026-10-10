# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode | None, l2: ListNode | None) -> ListNode | None:
        left=""
        right=""
        while (l1!=None):
            left+=str(l1.val)
            l1=l1.next
        while (l2!=None):
            right+=str(l2.val)
            l2=l2.next
        final=int(left[::-1])+int(right[::-1])
        dummy = ListNode(0)
        current = dummy
        
        for val in str(final)[::-1]:
            current.next = ListNode(int(val))
            current = current.next

        return dummy.next   
        