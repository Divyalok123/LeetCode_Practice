# Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

# You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if(head == None or head.next == None or head.next.next == None):
            return head
        
        evenPtr = head.next
        evenHead = head.next
        oddPtr = head
        
        while(evenPtr != None and evenPtr.next != None):
            oddPtr.next = oddPtr.next.next
            evenPtr.next = evenPtr.next.next
            oddPtr = oddPtr.next
            evenPtr = evenPtr.next
        oddPtr.next = evenHead
        
        return head