// LC143

class Solution {
public:
    void reorderList(ListNode* head) {
        if( (!head) || (!head->next) || (!head->next->next) ) return;
        stack<ListNode*> stack;
        ListNode* tmp = head;
        int ll_size = 0;
        while(tmp != nullptr)
        {
            stack.push(tmp);
            ll_size++;
            tmp = tmp->next;
        }

        tmp=head;
        // Insight : The replacements you have to 
        // do is size of linked list/2
        for(int i = 0; i<ll_size/2; i++)
        {
            ListNode* n = stack.top();
            stack.pop();
            n->next = tmp->next;
            tmp->next = n;
            tmp=tmp->next->next;
        }
        tmp->next = nullptr;
    }
};
