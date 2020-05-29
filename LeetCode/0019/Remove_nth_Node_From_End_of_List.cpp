/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) {
            return NULL;
        }
        
        int count = 0;
        ListNode* curr = head;
        ListNode* temp = head;
        while(curr) {
            if (count > n) {
                temp = temp->next;
            }
            curr = curr->next;
            count++;
        }
        if (count == n) {
            head = head->next;
            return head;
        }
        ListNode* ln2 = temp->next;
        temp->next = ln2->next;
        return head;
    }
};