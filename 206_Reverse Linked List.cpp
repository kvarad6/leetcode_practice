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
        
        //----------- Approach 1 | Iterative Approach -------------//

        ListNode* nextPtr;
        ListNode* currPtr = head;
        ListNode* prevPtr = NULL;

        //base case..
        if(head == NULL || head->next == NULL){
            return head;
        }

        while(currPtr!=NULL){
            nextPtr = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
        }
        return prevPtr; 

        //-------------- Recursive Approach | Recursive ---------------//
        //Pending...

    }
};
