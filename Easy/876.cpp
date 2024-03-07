// https://leetcode.com/problems/middle-of-the-linked-list/description/

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
class Solution {
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* hare = head;
        ListNode* tortoise = head;
        
        // Even Nodes => Hare stopping condition => hare =  NULL
        // Odd Nodes => Hare stopping condition => hare -> next = NULL
        
        while(hare && hare->next)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        return tortoise;
    }
    // O(N/2) Because we traverse only half of the Nodes
};
