/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// LC138 - Copy List with Random pointer
// O(n) time and memory complexity approach: Use a hash map to 
// keep track of old to new list pointers. 

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> old_to_new_map;
        Node* curr = head;
        while(curr) {
            old_to_new_map[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr)
        {
            old_to_new_map[curr]->next = old_to_new_map[curr->next];
            old_to_new_map[curr]->random = old_to_new_map[curr->random];
            curr = curr->next; 
        }
        return old_to_new_map[head];
    }
};

// LC138 - Copy List with Random pointer
// O(1) memory complexity approach with interleaving
// This solution interleaving the new nodes
// that you create. As you create these new nodes
// insert them into the existing list and then
// use the random pointer for the newly created node.
// This eliminates the need for extra memory
// https://leetcode.com/problems/copy-list-with-random-pointer/solutions/4003262/97-92-hash-table-linked-list
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node *curr = head;
        while(curr)
        {
            // Create interleaved nodes
            Node* new_interleaved_node = new Node(curr->val);
            new_interleaved_node->next = curr->next;
            curr->next = new_interleaved_node;
            curr = new_interleaved_node->next;
        }
        curr = head;
        while(curr) {
            if(curr->random)
            {
                // Tricky part: When inserting a new node
                // the random nodes move by one block. Hence
                // you take curr->random->next
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        // Create the new linked list
        Node *old_head = head;
        Node *new_head = head->next;
        Node *curr_old = old_head;
        Node *curr_new = new_head;
        while(curr_old)
        {
            // reconstruct the original linked 
            // list
            curr_old->next=curr_old->next->next;
            curr_new->next = curr_new->next ? curr_new->next->next : nullptr;
            curr_old = curr_old->next;
            curr_new = curr_new->next;
        }
        return new_head;
    }
};
