
// Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

// Definition for singly-linked list.
function ListNode(val, next) {
      this.val = (val===undefined ? 0 : val)
      this.next = (next===undefined ? null : next)
}
 
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

var oddEvenList = function(head) {
    if(head == null || head.next == null) return head;
    
    var oddPtr = head;
    var evenPtr = head.next;
    var evenHead = head.next;
    
    while(evenPtr != null && evenPtr.next != null)
    {
        oddPtr.next = oddPtr.next.next;
        evenPtr.next = evenPtr.next.next;
        oddPtr = oddPtr.next;
        evenPtr = evenPtr.next;
    }
    
    oddPtr.next = evenHead;
    return head;
};