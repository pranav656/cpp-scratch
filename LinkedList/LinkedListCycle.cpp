// Leetcode 141- Linked List cycle
// O(N) space complexity approach:
// Insert the visited nodes into a 
// hashset and check if the node
// is already present
// O(1) space complexity approach:
// Have two pointers, one fast pointer
// and one slow pointer, one moves through the list
// at 2x steps faster than the other. If they meet
// then the linked list has a cycle
// O(1) solution:
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            // fast jumps two pointers faster
            fast = fast->next->next;
            slow = slow->next;
            // if fast meets slow, there is a cycle
            if(fast && fast->next == slow) return true;
        }
        return false;
    }
};


/*
O(n) space complexity approach
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* curr = head;
        set<ListNode*> visited;
        while(curr != nullptr)
        {
            if(visited.find(curr) != visited.end())
            {
                return true;
            }
            visited.insert(curr);
            curr=curr->next;
        }
        return false;
    }
};*/
