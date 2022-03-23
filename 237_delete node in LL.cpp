//237 Delete Node in Linkedlist without head pointer..

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//using dereferencing pointers..
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        *node = *temp;
        delete temp;
        
    }
};
