// LC23 - Merge k Sorted Lists (Hard)
// Brute force approach is to merge all the lists and sort them, time complexity
// is O(nlogn). Alternative approach is to push all the elements into a priority queue
// and create the linked list popping elements out of the priority queue. Both
// these approaches involve using additional memory. There is an approach to
// obtain the result with O(1) additional memory. The approach is to merge 
// the lists two at a time. The time complexity of this approach is O(nlogk).
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (lists.size() == 0) return nullptr;
        while(n > 1)
        {
            cout<<n<<endl;
            for(int i = 0; i<n/2; i++)
            {
                // merge ith list and the ith list from the end
                lists[i] = mergeTwoLists(lists[i], lists[n-i-1]);
            }
            // This ensures that the lists already merged into other
            // lists are not taken into account for the next merge
            n=(n+1)/2;
        }
        return lists.front();
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // easy way to merge LLs but leads to memleak.
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                head->next = l1;
                l1=l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        head->next = (l1 == nullptr ) ? l2 : l1;
        return dummy->next;
    }
};
