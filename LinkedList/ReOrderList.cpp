// (TODO) LC143

class Solution {
public:
    void reorderList(ListNode* head) {
        int ll_size = 0;
        queue<ListNode*> nodes;
        ListNode* tmp_head = head;
        while(tmp_head != nullptr)
        {
            ll_size++;
            nodes.push(head);
            tmp_head = tmp_head->next;
        }
        cout<<ll_size<<endl;
        
        /*bool alternate = false;
        tmp_head = head;
        while(tmp_head != nullptr)
        {
            if(!alternate)
            {
                ListNode* queue_top = nodes.front();
                nodes.pop();
                ListNode *tmp = tmp_head->next;
                tmp_head->next = queue_top;
                queue_top = tmp;
                tmp_head = tmp_head->next;
            }
            else
            {
                //tmp_head = tmp_head->next;
            }
            alternate = !alternate;
        }*/

    }
};
