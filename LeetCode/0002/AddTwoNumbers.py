# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        num1 = 0
        num2 = 0
        i=0
        while (l1.next != None):
            num1 += l1.val * (10**i)
            l1 = l1.next
            i += 1
        num1 += l1.val * (10**i)
        i=0
        while (l2.next != None):
            num2 += l2.val * (10**i)
            l2 = l2.next
            i += 1
        num2 += l2.val * (10**i)
            
        sum = str(num1 + num2)
        
        l3 = ListNode()
        l3.val = int(sum[len(sum) - 1])
        if (len(sum) > 1):
            l4 = ListNode()
            l3.next = l4
        for i in range(len(sum) - 2,-1,-1):
            l4.val = int(sum[i])
            if (i != 0):
                l4.next = ListNode()
                l4 = l4.next
        return l3