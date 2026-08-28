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

        if(!head) return NULL;

        if(!head->next && n == 1) return NULL;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* l = dummy;
        ListNode* r = l; 

        while (n)
        {
            n--;
            r = r->next;
        }

        while(r->next != NULL)
        {
            l = l->next;
            r = r->next;
        }

        l->next = l->next->next;
        return dummy->next;
    }
};