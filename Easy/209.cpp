// https://leetcode.com/problems/reverse-linked-list/description/

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
    ListNode* reverseList(ListNode* head) {
        vector<int>nodes;
        ListNode* temp1 = head;
        while(temp1!=NULL)
        {
            nodes.push_back(temp1->val);
            temp1 = temp1->next;
        }
        ListNode* temp2 = head;
        int i = nodes.size()-1;
        while(temp2!=NULL)
        {
            temp2->val = nodes[i];
            i--;
            temp2=temp2->next;
        }
        return head;
    }
};
