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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        //create dummies and copies
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupTail = dummy; 
        ListNode* curr = head;

        int length = 0;
        ListNode* temp = head;

        //calculate legnght
        while(temp) 
        { 
            length++; 
            temp = temp->next; 
        }

        while(length >= k) // the remaining nodes stays the same
        {

            ListNode* groupHead = curr;
            ListNode* prev = NULL;
            ListNode* next = NULL;

            for (int i = 0; i < k; i++) 
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            prevGroupTail->next = prev;   // Link previous list to new start
            groupHead->next = curr;       // Link new end to remaining list
            prevGroupTail = groupHead;    // Update the 'tail' pointer

            length -= k;
        }

        return dummy->next;



    }
};