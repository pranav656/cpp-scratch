// LC83 - Remove duplicates from Sorted list
// Check for equality of next elements and update list
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* curr = head;
        while(curr->next != nullptr)
        {
            if(curr->val == curr->next->val)
            {
                ListNode*tmp = curr->next;
                curr->next = tmp->next;
                delete tmp;

            }
            else
            {
                curr=curr->next;
            }
        }
        return head;
    }
};
