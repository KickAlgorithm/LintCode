/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode *h(head);
        
        while(head && head->next) {
            if(head->val == head->next->val) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        
        return h;
    }
};