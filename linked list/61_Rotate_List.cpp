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
    ListNode* rotateRight(ListNode* head, int k) {

        //----------------- Approach 1 --------------------//

        //if k>length -> k%length.
        //Time Taken: 6ms | beats 41.9%

        if(head==NULL || k==0){
            return head;
        }
        int length = 1;
        ListNode* temp = head;

        // calculating length of ll
        while(temp->next!=NULL){
            temp = temp->next;
            length++;
        }

        //if k is multiple of length -> list will come bck to original configuration after rotating it.
        //(or)
        //if length is equal to the total no. of rotations, then need not to change anything, as ll will come back in its original state

        if(k%length==0){ //k==length
            return head;
        }
        
        
        //if total rotations is greater than length, we can use %
        //k%length are the actual rotations that needs to be performed
        if(k>length){
            k = k%length;
        }

        //connecting last node with the head
        temp->next = head;

        ListNode* dummy = head;
       
        for(int i=1;i<length-k;i++){
            dummy = dummy->next;
        }
        head = dummy->next;
        dummy->next = NULL;
        
        return head;
    }
};
