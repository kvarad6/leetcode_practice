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
 //------------- Approach 1 -------------//
 // Swapping values of nodes
 
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        int totalNodes = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            totalNodes++;
            temp = temp->next;
        }

        ListNode* tempStart = head;
        ListNode* tempEnd = head;
        for(int i=1;i<k;i++){
            tempStart = tempStart->next;
        }
        for(int i=1;i<totalNodes-k+1;i++){
            tempEnd = tempEnd->next;
        }
        int tempVal = tempStart->val;
        tempStart->val = tempEnd->val;
        tempEnd->val = tempVal;

        return head;
    }
};
