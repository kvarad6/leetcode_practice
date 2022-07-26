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
        
        //Using two pointers (fast and slow: one pass solution..)
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* fast = start;
        ListNode* slow = start;
        
        for(int i=1;i<=n;i++){
            fast = fast->next;
        }
        
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return start->next;
        
        /*
        //Using 2 pass solution..
        ListNode* temp = head;
        int total_node = 0;
        
        while(temp!=NULL){
            temp = temp->next;
            total_node++;
        }
        
        if(total_node == n){
            return head->next;
        }
        
        ListNode* prev_node = head;
        
        for(int i=0;i<total_node-n-1;i++){
            prev_node = prev_node->next;
        }
        prev_node->next = prev_node->next->next;
        
        return head;
        */
    }
    
};
