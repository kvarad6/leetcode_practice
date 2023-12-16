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
    void deleteNode(ListNode* node) {

        //---------- Approach 1 | assigning value of next node to the prev node..
        //TC: O(1)
        //SC: O(1)
        //to avoid the memory leak, assigning node->next to a temp variable and deleting the same..

        //At first, we are just changing the value, address hasn't been deleted.
        //To delete entire node properly, you required head of the LL.

        //We can replce current value with the next one, as it is given that node is not the last node in linked list.
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete(temp);
    }
};
