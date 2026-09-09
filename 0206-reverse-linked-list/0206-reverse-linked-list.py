class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None

        curr = head
        prev = None
        
        while curr:                 
            nxt = curr.next         
            curr.next = prev       
            prev = curr            
            curr = nxt
    
        return prev
        