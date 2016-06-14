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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        ListNode *pre = cur;
        int add = 0;
        
        while(l1 || l2 || add) {
            int a = (l1 == NULL? 0 : l1->val);
            int b = (l2 == NULL? 0 : l2->val);
            int c = a + b + add;
            add = c > 9? 1 : 0;
            int v = c%10;
            cur->val = v;
            ListNode *next = new ListNode(0);
            cur -> next = next;
            pre = cur;
            cur = next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        pre->next = NULL;
        return head;
    }
};