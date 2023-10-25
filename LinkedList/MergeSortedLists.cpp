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

// LC21 - Merge two sorted lists
// Iterative solution
// Go through the linked list and insert
// the lesser of elements into the newly created
// linked list. Time complexity O(m+n) where
// m and n are sizes of the linked lists.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr;
        // new node to store the result, the first
        // node is dummy and is meant for
        // simplicity of code
        ListNode * res = new ListNode(-1);
        // pointer to keep track of the newly
        // merged linked list
        ListNode * curr = res;
        ListNode *ptr1 = list1, *ptr2 = list2;

        while(ptr1 || ptr2)
        {
            // in case of empty pointer
            // copy the other list node by note
            if(!ptr1)
            {
                curr->next = ptr2;
                curr = curr-> next;
                ptr2 = ptr2->next;
                continue;
            }
            if(!ptr2)
            {
                curr->next= ptr1;
                curr = curr->next;
                ptr1=ptr1->next;
                continue;
            }
            // in case on of
            // the value is smaller
            if(ptr1->val >= ptr2->val)
            {
                curr->next = ptr2;
                curr = curr->next;
                ptr2=ptr2->next;
                continue;
            }
            else
            {
                curr->next = ptr1;
                curr=curr->next;
                ptr1=ptr1->next;
            }
        }
        // return next node as 
        // the first element is dummy
        return res->next;
    }
};
