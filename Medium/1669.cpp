// https://leetcode.com/problems/merge-in-between-linked-lists/

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev=list1;

        for(int i=0;i<a-1;i++)
        {
            prev=prev->next;
        }

        ListNode* track=prev;

        for(int i=a;i<=b;i++)
        {
            prev=prev->next;
        }

        track->next=list2;
        ListNode* end=list2;
        while(end->next!=NULL)
        {
            end=end->next;
        }

        end->next=prev->next;

        return list1;
    }
};
