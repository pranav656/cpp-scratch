// LC2 - Add two numbers represented by Linked Lists (Medium)
// Main tricks:
// digit = sum%10
// carry = sum/10
// iteration over two linked lists
// usage of dummy head pointer for a simpler implementation
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // common trick used in linked list problems
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;
        while(l1 || l2 || carry != 0)
        {
            // if one of the lists has terminated,
            // take zero
            int d1 = (l1 != nullptr) ? l1->val : 0;
            int d2 = (l2 != nullptr) ?l2->val : 0;
            int sum = d1 + d2 + carry;
            int digit = sum%10;
            carry = sum/10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;
            // check if the end of 
            // the lists has been reached
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        // the result pointer should point to
        // the next element of dummy pointer created
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};


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
