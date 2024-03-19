// LC19 
// Remove nth node from list:
// Find the size of the list in the first iteration, then
// in the second iteration, remove ll_size - n.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        ListNode* tmp = head;
        int ll_size = 0;
        while(tmp != nullptr)
        {
            ll_size++;
            tmp = tmp->next;
        }
        int target_node_to_change = ll_size - n-1;
        if(ll_size == 1 && n == 1) return nullptr;
        int curr = 0;
        tmp = head;
        while(tmp != nullptr)
        {
            // corner case where you need to remove the first node
            if(target_node_to_change ==-1) return head->next;
            if(curr == target_node_to_change)
            {
                ListNode* node_to_change = tmp;
                ListNode* node_to_remove = tmp->next;
                ListNode* node_to_link;
                if(tmp->next == nullptr)
                {
                    node_to_link = nullptr;
                }
                else
                {
                    node_to_link = tmp->next->next;
                }
                
                node_to_change->next = node_to_link;
                return head;
            }
            tmp=tmp->next;
            curr++;
        }
        return head;
    }
};
