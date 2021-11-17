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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryOver = 0;
        ListNode *l3 = new ListNode(0);
        ListNode *result = l3;
        
        while (true) {
            l3->val += carryOver;
            if (l1 != nullptr) {
                l3->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l3->val += l2->val;
                l2 = l2->next;
            }
            
            if (l3->val >= 10) {
                l3->val -= 10;
                carryOver = 1;
            }
            else {
                carryOver = 0;
            }
            
            if (l1 == nullptr && l2 == nullptr && carryOver == 0) {
                break;
            }
            else {
                l3->next = new ListNode(0);
                l3 = l3->next;
            }
        }
        
        return result;
    }
};
