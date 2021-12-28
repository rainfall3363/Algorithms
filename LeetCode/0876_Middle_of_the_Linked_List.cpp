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
    ListNode* middleNode(ListNode* head) {
        int nodes = 0;
        ListNode* np = head;
        
        while (np != nullptr) {
            nodes++;
            np = np->next;
        }
        np = head;
        for (int i = 0; i < (int)(nodes / 2); i++) {
            np = np->next;
        }
        
        return np;
    }
};
