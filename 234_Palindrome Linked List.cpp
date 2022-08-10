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
    bool isPalindrome(ListNode* head) {
        
        //Find the middle element using slow-fast pointers
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //Handling edge cases
        if(head==NULL || head->next==NULL){
            return true;
        }
        
        //Reverse the LL next to the middle element
        slow->next = reverseLL(slow->next);
        
        //Compares the nodes from original LL and reversed part
        slow = slow->next;
        ListNode* temp = head;
        
        while(slow!=NULL){
            if(temp->val!=slow->val){
                return false;
            }
        slow = slow->next;
        temp = temp->next;
        }
        return true;        
    }
    
    //Function to reverse LL
    ListNode* reverseLL(ListNode* head){
        
        ListNode* prev = NULL;
        ListNode* next_node = NULL;
        ListNode* curr = head;
        
        while(curr!=NULL){
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }
};
