// LC160 - Intersection of Two linked lists
// Practical applications/possible problem variations: Garbage collection/Memory leaks (Identifying shared locations in memory)
// Version Control systems : Understanding where branches diverge and confluict
// Bioinformatics: Find intersection points in DNA strands
// Possible solutions
// Brute Force:
// Iterate through both nodes one by one and check if there is equality ( a while inside a while loop )
// HashMap Based solution:
// Add the visited nodes in a solution, th first duplicated node is the intersection
// A solution based on just iteration is possible (needs a study later Solution 4 in link below :
//  https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/1093014/c-four-different-solutions/)
// Length Difference Solution:
// Below solution, find the difference of lengths and move the longer one by the difference,
// then check for equality
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0;
        int n = 0;
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        // obtain length of pointers
        while(ptr1 != nullptr)
        {
            m++;
            ptr1 = ptr1->next;
        }
        while(ptr2 != nullptr)
        {
            n++;
            ptr2 = ptr2->next;
        }
        int diff = abs(m - n);

        // move to the point such that the
        // lengh of the traversal is equalized
        if( m > n )
        {
            while(diff)
            {
                headA = headA->next;
                diff--;
            }
        }
        else
        {
            while(diff)
            {
                headB = headB->next;
                diff--;
            }
        }

        while(headA != nullptr && headB != nullptr)
        {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
