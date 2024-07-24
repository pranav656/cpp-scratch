// LC25 - Reverse Nodes in k-group (Hard)
// Problem variations/applications:
// Framereordering in video processing
// replay of game frames
// cryptography: reversing data in fixed
// size blocks is a back technique for some cryptographic
// algorithms
// Batch reversal in data processing
// Memory mangement: Page replacement algorithms reverse
// nodes in k-group to manage them effectively
// Solution approach
// Find the size of the list
// Keep reversing and linking lists until there exists
// elements that are less than k (track processed elements using
// counter)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // prev is to keep track of  the previous node to do 
        // the reversal, curr is the current element that
        // is being processed, start is the starting position 
        // of the current reversed linked list
        ListNode* prev = nullptr, *curr = head, *start = head;
        //This is the dummy node that is used for easy
        // processing. The reversed list starts from dummy->next
        ListNode* dummy = new ListNode(-1);
        // end is the end of the current reversed list
        // end indicates the end of the reversed linked list
        ListNode* end = dummy;

        // calculate the size of the linked list
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            n++;
            temp = temp->next;
        }

        // count is to track the current 
        // sub linked list, total count is to 
        // keep track of all the elements
        // processed till now, so as to
        // break out of the loop later
        int count = 0; int totalcount = 0;
        while(curr != nullptr)
        {
            // Reverse linked list 
            // Example : [1, 2, 3, 4 , 5], k = 2 
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
            totalcount++;
            // example for first sub linked list
            // After count = 2
            // sublinked list 1
            // nullptr <- 1 <- 2

            if(count == k)
            {
                // reset count to use for next list
                count = 0;
                // in the first iteration, it sets
                // dummy->next = node 2, 
                // subsequent iterations
                // it sets it to the last
                // element of the previous list
                // to the start of the current list
                //cout<<"end:"<<end->val<<endl;
                //cout<<"prev:"<<prev->val<<endl;
                //end:-1 (links dummy node to 2 in first iteration)
                //prev:2
                //end:1 (links 1 to 4 in second iteration, 4 is the first element 
                // after reversal)
                //prev:4
                end->next = prev;
                // The current start will be
                // the end of the next list. 
                // This is used for linking in the next
                // iteration
                end  = start;
                // this links the reversed
                // start node to the rest of the list

                
                // links the start (now end of list) to
                // the start of the current list
                //cout<<"start:"<<start->val<<endl;
                //cout<<"curr:"<<curr->val<<endl;
                //start:1
                //curr:3
                //start:3
                //curr:5
                start->next = curr;
                // start
                start = curr;
                prev = nullptr;

                // First part links the end (current start) of the sublist
                // second part links the start (current end) of the sublist

                // final check if there are more than k elements to be reversed
                // if not break
                if(n - totalcount < k) break;
            }
        }

        return dummy->next;
    }
};

//
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
