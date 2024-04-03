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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //-------------- Approach 1 ---------------------//
        // Total nodes -> Transverse till nth node, connect nth prev with nth next..
        // imp: need to remove node from last, not from the first..
        // Two pass solution

        ListNode* temp = head;
        int totalNodes = 0;

        while(temp!=NULL){
            totalNodes++;
            temp = temp->next;
        }

        if(totalNodes == n){
            return head->next;
        }

        ListNode* prevNode = head;

        for(int i=0;i<totalNodes-n-1;i++){
            prevNode = prevNode->next;
        }
        prevNode->next = prevNode->next->next;

        return head;

        //--------------- Approach 2 ------------------//

        // Using Fast-Slow pointers..
        // One pass solution..
        
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        //handle the case when n = total nodes (head need to be removed)
        if(fast==NULL){
            return head->next;
        }

        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
