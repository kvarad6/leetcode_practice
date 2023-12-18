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

        //------------- Approach 1 --------------------//
        
        //Finding length of LL -> Middle Element -> Transverse

        int count = 0;
        ListNode* temp = head;

        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        int middle = count/2;

        ListNode* currPtr = head;
        for(int i=0;i<middle;i++){
            currPtr = currPtr->next;
        }
        return currPtr;

        //-------------- Approach 2 -----------------------//

        // Using Fast n Slow 

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
