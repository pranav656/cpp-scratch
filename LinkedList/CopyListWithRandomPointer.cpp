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
