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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode dummy(0);
        ListNode* point = &dummy;
        ListNode* ans = &dummy;



        while (list1 != NULL && list2 != NULL) 
        {
            if (list1->val <= list2->val) 
            {
                point->next = list1;
                list1 = list1->next;
            } 
            else 
            {
                point->next = list2;
                list2 = list2->next;
            }
            point = point->next;
        }

        if (list1 != NULL) 
        point->next = list1;
       
        else 
        point->next = list2;
    
        ans = ans->next;
        return ans;

    }
};