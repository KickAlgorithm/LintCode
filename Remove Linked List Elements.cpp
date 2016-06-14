/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        while(head && head->val == val) head = head->next;
        ListNode *res(head);
        
        while(head && head->next) {
            if(head->next->val == val) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        
        return res;
    }
};